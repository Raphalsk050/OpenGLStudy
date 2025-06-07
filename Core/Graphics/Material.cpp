#include "Material.h"

namespace GLStudy {

void Material::LoadTextures() {
    if(has_albedo && !albedo_map) { albedo_map = std::make_shared<Texture2D>(); albedo_map->LoadFromFile(albedo_path); }
    if(has_normal && !normal_map) { normal_map = std::make_shared<Texture2D>(); normal_map->LoadFromFile(normal_path); }
    if(has_specular && !specular_map) { specular_map = std::make_shared<Texture2D>(); specular_map->LoadFromFile(specular_path); }
    if(has_roughness && !roughness_map) { roughness_map = std::make_shared<Texture2D>(); roughness_map->LoadFromFile(roughness_path); }
    if(has_ao && !ao_map) { ao_map = std::make_shared<Texture2D>(); ao_map->LoadFromFile(ao_path); }
    if(has_emissive && !emissive_map) { emissive_map = std::make_shared<Texture2D>(); emissive_map->LoadFromFile(emissive_path); }
}

}
