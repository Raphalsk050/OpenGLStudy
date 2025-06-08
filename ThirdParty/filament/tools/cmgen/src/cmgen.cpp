
#include "ProgressUpdater.h"

#include <ibl/Cubemap.h>
#include <ibl/CubemapIBL.h>
#include <ibl/CubemapSH.h>
#include <ibl/CubemapUtils.h>
#include <ibl/Image.h>
#include <ibl/utilities.h>

#include <imageio/ImageDecoder.h>
#include <imageio/ImageEncoder.h>

#include <image/Ktx1Bundle.h>
#include <image/ColorTransform.h>

#include "third_party/filament/libs/utils/include/utils/JobSystem.h"
#include "third_party/filament/libs/utils/include/utils/Path.h"
#include "third_party/filament/libs/utils/include/utils/algorithm.h"

#include "third_party/filament/libs/math/include/math/scalar.h"
#include "third_party/filament/libs/math/include/math/vec4.h"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

#include <string.h>

#include <getopt.h>


using namespace filament::math;
using namespace filament::ibl;
using namespace image;

// -----------------------------------------------------------------------------------------------

enum class ShFile {
    SH_NONE, SH_FILE, SH_TEXT, SH_BIN
};

static const size_t DFG_LUT_DEFAULT_SIZE = 128;
static const size_t IBL_DEFAULT_SIZE = 256;
static const size_t IBL_DEFAULT_MIN_LOD_SIZE = 16;

enum class OutputType {
    FACES, KTX, EQUIRECT, OCTAHEDRON
};

static image::ImageEncoder::Format g_format = image::ImageEncoder::Format::PNG;
static OutputType g_type = OutputType::FACES;
static std::string g_compression;
static bool g_extract_faces = false;
static float g_extract_blur = 0.0;
static utils::Path g_extract_dir;

static size_t g_output_size = 0;
static size_t g_min_lod_size = 0;

static bool g_quiet = false;
static bool g_debug = false;

static size_t g_sh_compute = 0;
static bool g_sh_output = false;
static bool g_sh_shader = false;
static bool g_sh_irradiance = false;
static float g_sh_window = 0.0f; // <0 none, 0=auto, or cutoff
static bool g_noclamp = true;
static ShFile g_sh_file = ShFile::SH_NONE;
static utils::Path g_sh_filename;
static std::unique_ptr<filament::math::float3[]> g_sh_coefficients;

static bool g_is_mipmap = false;
static utils::Path g_is_mipmap_dir;
static bool g_prefilter = false;
static utils::Path g_prefilter_dir;
static bool g_dfg = false;
static utils::Path g_dfg_filename;
static bool g_dfg_multiscatter = false;
static bool g_dfg_cloth = false;

static bool g_ibl_irradiance = false;
static bool g_ibl_no_prefilter = false;
static utils::Path g_ibl_irradiance_dir;

static bool g_deploy = false;
static utils::Path g_deploy_dir;

static size_t g_num_samples = 1024;

static bool g_mirror = false;

// -----------------------------------------------------------------------------------------------

static void generateMipmaps(utils::JobSystem& js, std::vector<Cubemap>& levels,
        std::vector<Image>& images);
static void sphericalHarmonics(utils::JobSystem& js, const utils::Path& iname,
        const Cubemap& inputCubemap);
static void iblRoughnessPrefilter(
        utils::JobSystem& js, const utils::Path& iname, const std::vector<Cubemap>& levels,
        bool prefilter, const utils::Path& dir);
static void iblDiffuseIrradiance(utils::JobSystem& js, const utils::Path& iname,
        const std::vector<Cubemap>& levels, const utils::Path& dir);
static void iblMipmapPrefilter(utils::JobSystem& js, const utils::Path& iname,
        const std::vector<Image>& images, const std::vector<Cubemap>& levels,
        const utils::Path& dir);
static void iblLutDfg(utils::JobSystem& js, const utils::Path& filename, size_t size,
        bool multiscatter,
        bool cloth);
static void extractCubemapFaces(utils::JobSystem& js, const utils::Path& iname, const Cubemap& cm,
        const utils::Path& dir);
static void outputSh(std::ostream& out, const std::unique_ptr<filament::math::float3[]>& sh,
        size_t numBands);
static void outputBinarySh(std::ostream& out, const std::unique_ptr<filament::math::float3[]>& sh,
        size_t numBands);
static void UTILS_UNUSED outputSpectrum(std::ostream& out,
        const std::unique_ptr<filament::math::float3[]>& sh, size_t numBands);
static void saveImage(const std::string& path, ImageEncoder::Format format, const Image& image,
        const std::string& compression);
static LinearImage toLinearImage(const Image& image);
static void exportKtxFaces(Ktx1Bundle& container, uint32_t miplevel, const Cubemap& cm);

// -----------------------------------------------------------------------------------------------

static void printUsage(char* name) {
    std::string exec_name(utils::Path(name).getName());
    std::string usage(
            "CMGEN is a command-line tool for generating SH and mipmap levels from an env map.\n"
            "Cubemaps and equirectangular formats are both supported, automatically detected \n"
            "according to the aspect ratio of the source image.\n"
            "\n"
            "Usages:\n"
            "    CMGEN [options] <input-file>\n"
            "    CMGEN [options] <uv[N]>\n"
            "\n"
            "Supported input formats:\n"
            "    PNG, 8 and 16 bits\n"
            "    Radiance (.hdr)\n"
            "    Photoshop (.psd), 16 and 32 bits\n"
            "    OpenEXR (.exr)\n"
            "\n"
            "Options:\n"
            "   --help, -h\n"
            "       Print this message\n\n"
            "   --license\n"
            "       Print copyright and license information\n\n"
            "   --quiet, -q\n"
            "       Quiet mode. Suppress all non-error output\n\n"
            "   --type=[cubemap|equirect|octahedron|ktx], -t [cubemap|equirect|octahedron|ktx]\n"
            "       Specify output type (default: cubemap)\n\n"
            "   --format=[exr|hdr|psd|rgbm|rgb32f|png|dds|ktx], -f [format]\n"
            "       Specify output file format. ktx implies -type=ktx.\n"
            "       KTX files are always KTX1 files, not KTX2.\n"
            "       They are encoded with 3-channel RGB_10_11_11_REV data\n\n"
            "   --compression=COMPRESSION, -c COMPRESSION\n"
            "       Format specific compression:\n"
            "           KTX: ignored\n"
            "           PNG: Ignored\n"
            "           PNG RGBM: Ignored\n"
            "           Radiance: Ignored\n"
            "           Photoshop: 16 (default), 32\n"
            "           OpenEXR: RAW, RLE, ZIPS, ZIP, PIZ (default)\n"
            "           DDS: 8, 16 (default), 32\n\n"
            "   --size=power-of-two, -s power-of-two\n"
            "       Size of the output cubemaps (base level), 256 by default\n"
            "       Also applies to DFG LUT\n\n"
            "   --deploy=dir, -x dir\n"
            "       Generate everything needed for deployment into <dir>\n\n"
            "   --extract=dir\n"
            "       Extract faces of the cubemap into <dir>\n\n"
            "   --extract-blur=roughness\n"
            "       Blurs the cubemap before saving the faces using the roughness blur\n\n"
            "   --clamp\n"
            "       Clamp environment before processing\n\n"
            "   --no-mirror\n"
            "       Skip mirroring of generated cubemaps (for assets with mirroring already backed in)\n\n"
            "   --ibl-samples=numSamples\n"
            "       Number of samples to use for IBL integrations (default 1024)\n\n"
            "   --ibl-ld=dir\n"
            "       Roughness pre-filter into <dir>\n\n"
            "   --sh-shader\n"
            "       Generate irradiance SH for shader code\n\n"
            "\n"
            "Private use only:\n"
            "   --ibl-dfg=filename.[exr|hdr|psd|png|rgbm|rgb32f|dds|h|hpp|c|cpp|inc|txt]\n"
            "       Compute the IBL DFG LUT\n\n"
            "   --ibl-dfg-multiscatter\n"
            "       If --ibl-dfg is set, computes the DFG for multi-scattering GGX\n\n"
            "   --ibl-dfg-cloth\n"
            "       If --ibl-dfg is set, adds a 3rd channel to the DFG for cloth shading\n\n"
            "   --ibl-is-mipmap=dir\n"
            "       Generate mipmap for pre-filtered importance sampling\n\n"
            "   --ibl-irradiance=dir\n"
            "       Diffuse irradiance into <dir>\n\n"
            "   --ibl-no-prefilter\n"
            "       Use importance sampling instead of prefiltered importance sampling\n\n"
            "   --ibl-min-lod-size\n"
            "       Minimum LOD size [default: 16]\n\n"
            "   --sh=bands\n"
            "       SH decomposition of input cubemap\n\n"
            "   --sh-output=filename.[exr|hdr|psd|rgbm|rgb32f|png|dds|txt|bin]\n"
            "       SH output format. The filename extension determines the output format\n\n"
            "   --sh-irradiance, -i\n"
            "       Irradiance SH coefficients\n\n"
            "   --sh-window=cutoff|no|auto (default), -w cutoff|no|auto (default)\n"
            "       SH windowing to reduce ringing\n\n"
            "   --debug, -d\n"
            "       Generate extra data for debugging\n\n"
    );
    const std::string from("CMGEN");
    for (size_t pos = usage.find(from); pos != std::string::npos; pos = usage.find(from, pos)) {
         usage.replace(pos, from.length(), exec_name);
    }
    printf("%s", usage.c_str());
}

static void license() {
    static const char *license[] = {
        #include "licenses/licenses.inc"
        nullptr
    };

    const char **p = &license[0];
    while (*p)
        std::cout << *p++ << std::endl;
}

static int handleCommandLineArgments(int argc, char* argv[]) {
    static constexpr const char* OPTSTR = "hqidt:f:c:s:x:w:S:";
    static const struct option OPTIONS[] = {
            { "help",                       no_argument, nullptr, 'h' },
            { "license",                    no_argument, nullptr, 'l' },
            { "quiet",                      no_argument, nullptr, 'q' },
            { "type",                 required_argument, nullptr, 't' },
            { "format",               required_argument, nullptr, 'f' },
            { "compression",          required_argument, nullptr, 'c' },
            { "size",                 required_argument, nullptr, 's' },
            { "extract",              required_argument, nullptr, 'e' },
            { "extract-blur",         required_argument, nullptr, 'r' },
            { "sh",                   optional_argument, nullptr, 'z' },
            { "sh-output",            required_argument, nullptr, 'o' },
            { "sh-irradiance",              no_argument, nullptr, 'i' },
            { "sh-shader",                  no_argument, nullptr, 'b' },
            { "sh-window",            required_argument, nullptr, 'w' },
            { "clamp",                      no_argument, nullptr, 'K' },
            { "ibl-is-mipmap",        required_argument, nullptr, 'y' },
            { "ibl-ld",               required_argument, nullptr, 'p' },
            { "ibl-irradiance",       required_argument, nullptr, 'P' },
            { "ibl-dfg",              required_argument, nullptr, 'a' },
            { "ibl-dfg-multiscatter",       no_argument, nullptr, 'u' },
            { "ibl-dfg-cloth",              no_argument, nullptr, 'C' },
            { "ibl-no-prefilter",           no_argument, nullptr, 'n' },
            { "ibl-min-lod-size",     required_argument, nullptr, 'S' },
            { "ibl-samples",          required_argument, nullptr, 'k' },
            { "deploy",               required_argument, nullptr, 'x' },
            { "no-mirror",                  no_argument, nullptr, 'm' },
            { "debug",                      no_argument, nullptr, 'd' },
            { nullptr, 0, nullptr, 0 }  // termination of the option list
    };
    int opt;
    int option_index = 0;
    int num_sh_bands = 3;
    bool format_specified = false;
    bool type_specified = false;
    bool ktx_format_requested = false;
    while ((opt = getopt_long(argc, argv, OPTSTR, OPTIONS, &option_index)) >= 0) {
        std::string arg(optarg ? optarg : "");
        switch (opt) {
            default:
            case 'h':
                printUsage(argv[0]);
                exit(0);
                break; // NOLINT
            case 'l':
                license();
                exit(0);
                break; // NOLINT
            case 'q':
                g_quiet = true;
                break;
            case 't':
                if (arg == "cubemap") {
                    g_type = OutputType::FACES;
                    type_specified = true;
                }
                if (arg == "ktx") {
                    g_type = OutputType::KTX;
                    type_specified = true;
                }
                if ((arg == "equirect") || (arg == "equirectangular")) {
                    g_type = OutputType::EQUIRECT;
                    type_specified = true;
                }
                if (arg == "octahedron") {
                    g_type = OutputType::OCTAHEDRON;
                    type_specified = true;
                }
                break;
            case 'f':
                if (arg == "png") {
                    g_format = ImageEncoder::Format::PNG;
                    format_specified = true;
                }
                if (arg == "hdr") {
                    g_format = ImageEncoder::Format::HDR;
                    format_specified = true;
                }
                if (arg == "rgbm") {
                    g_format = ImageEncoder::Format::RGBM;
                    format_specified = true;
                }
                if (arg == "rgb32f") {
                    g_format = ImageEncoder::Format::RGB_10_11_11_REV;
                    format_specified = true;
                }
                if (arg == "exr") {
                    g_format = ImageEncoder::Format::EXR;
                    format_specified = true;
                }
                if (arg == "psd") {
                    g_format = ImageEncoder::Format::PSD;
                    format_specified = true;
                }
                if (arg == "dds") {
                    g_format = ImageEncoder::Format::DDS_LINEAR;
                    format_specified = true;
                }
                if (arg == "ktx") {
                    ktx_format_requested = true;
                    format_specified = true;
                }
                break;
            case 'c':
                g_compression = arg;
                break;
            case 's':
                g_output_size = std::stoul(arg);
                if (!isPOT(g_output_size)) {
                    std::cerr << "output size must be a power of two" << std::endl;
                    exit(0);
                }
                break;
            case 'S':
                g_min_lod_size = std::stoul(arg);
                if (!isPOT(g_min_lod_size)) {
                    std::cerr << "min LOD size must be a power of two" << std::endl;
                    exit(0);
                }
                break;
            case 'z':
                g_sh_compute = 1;
                g_sh_output = true;
                try {
                    num_sh_bands = std::stoi(arg);
                } catch (std::invalid_argument &e) {
                    // keep default value
                }
                break;
            case 'o':
                g_sh_compute = 1;
                g_sh_output = true;
                g_sh_file = ShFile::SH_FILE;
                g_sh_filename = arg;
                if (g_sh_filename.getExtension() == "txt") {
                    g_sh_file = ShFile::SH_TEXT;
                } else if (g_sh_filename.getExtension() == "bin") {
                    g_sh_file = ShFile::SH_BIN;
                }
                break;
            case 'w':
                if (arg == "auto") { g_sh_window = 0.0f; }
                else if (arg == "no") { g_sh_window = -1.0f; }
                else { g_sh_window = std::stof(arg); }
                break;
            case 'K':
                g_noclamp = false;
                break;
            case 'i':
                g_sh_compute = 1;
                g_sh_irradiance = true;
                break;
            case 'b':
                g_sh_compute = 1;
                g_sh_irradiance = true;
                g_sh_shader = true;
                break;
            case 'e':
                g_extract_dir = arg;
                g_extract_faces = true;
                break;
            case 'r':
                g_extract_blur = std::stod(arg);
                if (g_extract_blur < 0 || g_extract_blur > 1) {
                    std::cerr << "roughness (blur) parameter must be between 0.0 and 1.0" <<
                    std::endl;
                    exit(0);
                }
                break;
            case 'y':
                g_is_mipmap = true;
                g_is_mipmap_dir = arg;
                break;
            case 'p':
                g_prefilter = true;
                g_prefilter_dir = arg;
                break;
            case 'P':
                g_ibl_irradiance = true;
                g_ibl_irradiance_dir = arg;
                break;
            case 'n':
                g_ibl_no_prefilter = true;
                break;
            case 'a':
                g_dfg = true;
                g_dfg_filename = arg;
                break;
            case 'u':
                g_dfg_multiscatter = true;
                break;
            case 'C':
                g_dfg_cloth = true;
                break;
            case 'k':
                g_num_samples = (size_t)std::stoi(arg);
                break;
            case 'x':
                g_deploy = true;
                g_deploy_dir = arg;
                break;
            case 'd':
                g_debug = true;
                break;
            case 'm':
                g_mirror = true;
                break;
        }
    }

    if (ktx_format_requested) {
        g_type = OutputType::KTX;
        type_specified = true;
    }

    if (g_deploy && !type_specified) {
        g_type = OutputType::FACES;
    }

    if (g_deploy && !format_specified) {
        g_format = ImageEncoder::Format::RGB_10_11_11_REV;
    }

    if (num_sh_bands && g_sh_compute) {
        g_sh_compute = (size_t) num_sh_bands;
    }
    return optind;
}

int main(int argc, char* argv[]) {
    utils::JobSystem js;
    js.adopt();

    int option_index = handleCommandLineArgments(argc, argv);
    int num_args = argc - option_index;
    if (!g_dfg && num_args < 1) {
        printUsage(argv[0]);
        return 1;
    }

    if (g_dfg) {
        if (!g_quiet) {
            std::cout << "Generating IBL DFG LUT..." << std::endl;
        }
        size_t size = g_output_size ? g_output_size : DFG_LUT_DEFAULT_SIZE;
        iblLutDfg(js, g_dfg_filename, size, g_dfg_multiscatter, g_dfg_cloth);
        if (num_args < 1) return 0;
    }

    std::string command(argv[option_index]);
    utils::Path iname(command);

    if (g_deploy) {
        utils::Path sh_dir = g_deploy_dir;

        // KTX files are self-contained and do not need to live in a subfolder.
        if (g_type != OutputType::KTX) {
            sh_dir += iname.getNameWithoutExtension();
        }

        // generate pre-scaled irradiance sh to text file
        g_sh_compute = 3;
        g_sh_shader = true;
        g_sh_irradiance = true;
        if (g_sh_file == ShFile::SH_NONE) {
            g_sh_file = ShFile::SH_TEXT;
            g_sh_filename = sh_dir + "sh.txt";
        } else {
            g_sh_filename = sh_dir + g_sh_filename.getName();
        }
        g_sh_output = true;

        // faces
        g_extract_dir = g_deploy_dir;
        g_extract_faces = true;

        // prefilter
        g_prefilter = true;
        g_prefilter_dir = g_deploy_dir;
    }

    // Images store the actual data
    std::vector<Image> images;

    // Cubemaps are just views on Images
    std::vector<Cubemap> levels;

    if (iname.exists()) {
        if (!g_quiet) {
            std::cout << "Decoding image..." << std::endl;
        }
        std::ifstream input_stream(iname.getPath(), std::ios::binary);
        LinearImage linputImage = ImageDecoder::decode(input_stream, iname.getPath());
        if (!linputImage.isValid()) {
            std::cerr << "Unable to open image: " << iname.getPath() << std::endl;
            exit(1);
        }
        if (linputImage.getChannels() != 3) {
            std::cerr << "Input image must be RGB (3 channels)! This image has "
                      << linputImage.getChannels() << " channels." << std::endl;
            exit(1);
        }

        // Convert from LinearImage to the deprecated Image object which is used throughout cmgen.
        const size_t width = linputImage.getWidth(), height = linputImage.getHeight();
        Image inputImage(width, height);
        memcpy(inputImage.getData(), linputImage.getPixelRef(), height * inputImage.getBytesPerRow());

        if (!g_noclamp) {
            CubemapUtils::clamp(inputImage);
        }

        if ((isPOT(width) && (width * 3 == height * 4)) ||
            (isPOT(height) && (height * 3 == width * 4))) {
            // This is cross cubemap
            size_t dim = g_output_size ? g_output_size : IBL_DEFAULT_SIZE;
            if (!g_quiet) {
                std::cout << "Loading cross... " << std::endl;
            }

            Image temp;
            Cubemap cml = CubemapUtils::create(temp, dim);
            CubemapUtils::crossToCubemap(js, cml, inputImage);
            images.push_back(std::move(temp));
            levels.push_back(std::move(cml));
        } else if (width == 2 * height) {
            // we assume a spherical (equirectangular) image, which we will convert to a cross image
            size_t dim = g_output_size ? g_output_size : IBL_DEFAULT_SIZE;
            if (!g_quiet) {
                std::cout << "Converting equirectangular image... " << std::endl;
            }
            Image temp;
            Cubemap cml = CubemapUtils::create(temp, dim);
            CubemapUtils::equirectangularToCubemap(js, cml, inputImage);
            images.push_back(std::move(temp));
            levels.push_back(std::move(cml));
        } else {
            std::cerr << "Aspect ratio not supported: " << width << "x" << height << std::endl;
            std::cerr << "Supported aspect ratios:" << std::endl;
            std::cerr << "  2:1, lat/long or equirectangular" << std::endl;
            std::cerr << "  3:4, vertical cross (height must be power of two)" << std::endl;
            std::cerr << "  4:3, horizontal cross (width must be power of two)" << std::endl;
            exit(0);
        }
    } else {
        if (!g_quiet) {
            std::cout << iname << " does not exist; generating UV grid..." << std::endl;
        }

        size_t dim = g_output_size ? g_output_size : IBL_DEFAULT_SIZE;
        Image temp;
        Cubemap cml = CubemapUtils::create(temp, dim);

        unsigned int p = 0;
        std::string name = iname.getNameWithoutExtension();
        if (sscanf(name.c_str(), "uv%u", &p) == 1) { // NOLINT
            CubemapUtils::generateUVGrid(js, cml, p, p);
        } else if (sscanf(name.c_str(), "u%u", &p) == 1) { // NOLINT
            CubemapUtils::generateUVGrid(js, cml, p, 1);
        } else if (sscanf(name.c_str(), "v%u", &p) == 1) { // NOLINT
            CubemapUtils::generateUVGrid(js, cml, 1, p);
        } else if (sscanf(name.c_str(), "brdf%u", &p) == 1) { // NOLINT
            float linear_roughness = sq(p / std::log2(dim));
            CubemapIBL::brdf(js, cml, linear_roughness);
        } else {
            CubemapUtils::generateUVGrid(js, cml, 1, 1);
        }

        images.push_back(std::move(temp));
        levels.push_back(std::move(cml));
    }

    // we mirror by default -- the mirror option in fact un-mirrors.
    g_mirror = !g_mirror;
    if (g_mirror) {
        if (!g_quiet) {
            std::cout << "Mirroring..." << std::endl;
        }
        Image temp;
        Cubemap cml = CubemapUtils::create(temp, levels[0].getDimensions());
        CubemapUtils::mirrorCubemap(js, cml, levels[0]);
        std::swap(levels[0], cml);
        std::swap(images[0], temp);
    } else {
        if (!g_quiet) {
            std::cout << "Skipped mirroring." << std::endl;
        }
    }

    // make the cubemap seamless
    levels[0].makeSeamless();

    // Now generate all the mipmap levels
    generateMipmaps(js, levels, images);

    if (g_sh_compute) {
        if (!g_quiet) {
            std::cout << "Spherical harmonics..." << std::endl;
        }
        Cubemap const& cm(levels[0]);
        sphericalHarmonics(js, iname, cm);
    }

    if (g_is_mipmap) {
        if (!g_quiet) {
            std::cout << "IBL mipmaps for prefiltered importance sampling..." << std::endl;
        }
        iblMipmapPrefilter(js, iname, images, levels, g_is_mipmap_dir);
    }

    if (g_prefilter) {
        if (!g_quiet) {
            std::cout << "IBL prefiltering..." << std::endl;
        }
        iblRoughnessPrefilter(js, iname, levels, !g_ibl_no_prefilter, g_prefilter_dir);
    }

    if (g_ibl_irradiance) {
        if (!g_quiet) {
            std::cout << "IBL diffuse irradiance..." << std::endl;
        }
        iblDiffuseIrradiance(js, iname, levels, g_ibl_irradiance_dir);
    }

    if (g_extract_faces) {
        Cubemap const& cm(levels[0]);
        if (g_extract_blur != 0) {
            ProgressUpdater updater(1);
            if (!g_quiet) {
                std::cout << "Blurring..." << std::endl;
                updater.start();
            }
            const float linear_roughness = g_extract_blur * g_extract_blur;
            const size_t dim = g_output_size ? g_output_size : cm.getDimensions();
            Image image;
            Cubemap blurred = CubemapUtils::create(image, dim);
            CubemapIBL::roughnessFilter(js, blurred, levels, linear_roughness, g_num_samples,
                    float3{ 1, 1, 1 }, !g_ibl_no_prefilter,
                    [](size_t index, float v, void* userdata) {
                        if (!g_quiet) {
                            ((ProgressUpdater*) userdata)->update(index, v);
                        }
                    }, &updater);
            if (!g_quiet) {
                updater.stop();
                std::cout << "Extract faces..." << std::endl;
            }
            extractCubemapFaces(js, iname, blurred, g_extract_dir);
        } else {
            if (!g_quiet) {
                std::cout << "Extract faces..." << std::endl;
            }
            extractCubemapFaces(js, iname, cm, g_extract_dir);
        }
    }

    return 0;
}

void generateMipmaps(utils::JobSystem& js, std::vector<Cubemap>& levels,
        std::vector<Image>& images) {
    Image temp;
    const Cubemap& base(levels[0]);
    size_t dim = base.getDimensions();
    size_t mipLevel = 0;
    while (dim > 1) {
        dim >>= 1u;
        Cubemap dst = CubemapUtils::create(temp, dim);
        const Cubemap& src(levels[mipLevel++]);
        CubemapUtils::downsampleCubemapLevelBoxFilter(js, dst, src);
        dst.makeSeamless();
        images.push_back(std::move(temp));
        levels.push_back(std::move(dst));
    }
}

void sphericalHarmonics(utils::JobSystem& js, const utils::Path& iname, const Cubemap& inputCubemap) {
    std::unique_ptr<filament::math::float3[]> sh;
    if (g_sh_shader) {
        sh = CubemapSH::computeSH(js, inputCubemap, 3, true);
    } else {
        sh = CubemapSH::computeSH(js, inputCubemap, g_sh_compute, g_sh_irradiance);
    }

    if (g_sh_window >= 0) {
        CubemapSH::windowSH(sh, g_sh_compute, g_sh_window);
    }

    if (g_sh_shader) {
        CubemapSH::preprocessSHForShader(sh);
    }

    if (!g_quiet && g_sh_output) {
        outputSh(std::cout, sh, g_sh_compute);
    }

    if (g_sh_file != ShFile::SH_NONE || g_debug) {
        Image image;
        const size_t dim = g_output_size ? g_output_size : inputCubemap.getDimensions();
        Cubemap cm = CubemapUtils::create(image, dim);

        if (g_sh_file != ShFile::SH_NONE) {
            utils::Path outputDir(g_sh_filename.getAbsolutePath().getParent());
            if (!outputDir.exists()) {
                outputDir.mkdirRecursive();
            }

            if (g_sh_shader) {
                CubemapSH::renderPreScaledSH3Bands(js, cm, sh);
            } else {
                CubemapSH::renderSH(js, cm, sh, g_sh_compute);
            }

            cm.makeSeamless();

            if (g_sh_file == ShFile::SH_FILE) {
                Image outputImage;
                if (g_type == OutputType::OCTAHEDRON) {
                    size_t outputDimension = cm.getDimensions();
                    outputImage = Image(outputDimension, outputDimension);
                    CubemapUtils::cubemapToOctahedron(js, outputImage, cm);
