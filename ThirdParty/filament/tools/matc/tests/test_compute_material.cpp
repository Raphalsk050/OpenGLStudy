
#include <gtest/gtest.h>

#include <matc/MaterialCompiler.h>

#include "TestMaterialCompiler.h"

#include "third_party/filament/libs/utils/include/utils/JobSystem.h"

static std::string_view jsonMaterialSourceSimple(R"(
material {
    name: test_compute,
    domain: compute,
    groupSize: [8, 8, 1],
    parameters: [
    ]
}
compute {
    void compute() {
    }
}
)");

TEST(TestComputeMaterial, JsonMaterialCompilerSimple) {
    matc::MaterialCompiler rawCompiler;
    TestMaterialCompiler compiler(rawCompiler);

    filamat::MaterialBuilder::init();
    filamat::MaterialBuilder builder;

    bool result = compiler.parseMaterial(jsonMaterialSourceSimple.data(), jsonMaterialSourceSimple.size(), builder);

    EXPECT_TRUE(result);

    utils::JobSystem js;
    js.adopt();

    auto package = builder.build(js);

    EXPECT_TRUE(package.isValid());

    js.emancipate();
    filamat::MaterialBuilder::shutdown();
}

