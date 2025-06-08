
#include <gtest/gtest.h>

#include "filamat/MaterialBuilder.h"

#include "Includes.h"

#include "MockIncluder.h"

#include "third_party/filament/libs/utils/include/utils/CString.h"
#include "third_party/filament/libs/utils/include/utils/JobSystem.h"

#include <memory>

using namespace utils;

// -------------------------------------------------------------------------------------------------

TEST(IncludeParser, NoIncludes) {
    utils::CString code("// no includes");
    std::vector<filamat::FoundInclude> result = filamat::parseForIncludes(code);
    EXPECT_TRUE(result.size() == 0);
}

TEST(IncludeParser, SingleInclude) {
    utils::CString code(R"(#include "foobar.h")");
    auto result = filamat::parseForIncludes(code);
    EXPECT_EQ(1, result.size());
    EXPECT_STREQ("foobar.h", result[0].name.c_str());
    EXPECT_EQ(0, result[0].startPosition);
    EXPECT_EQ(19, result[0].length);
    EXPECT_EQ(1, result[0].line);
}

TEST(IncludeParser, MultipleIncludes) {
    utils::CString code("#include \"foobar.h\"\n#include \"bazbarfoo.h\"");
    auto result = filamat::parseForIncludes(code);

    EXPECT_EQ(2, result.size());
    EXPECT_STREQ("foobar.h", result[0].name.c_str());
    EXPECT_EQ(0, result[0].startPosition);
    EXPECT_EQ(19, result[0].length);
    EXPECT_EQ(1, result[0].line);

    EXPECT_STREQ("bazbarfoo.h", result[1].name.c_str());
    EXPECT_EQ(20, result[1].startPosition);
    EXPECT_EQ(22, result[1].length);
    EXPECT_EQ(2, result[1].line);
}

TEST(IncludeParser, EmptyInclude) {
    utils::CString code("#include \"\"");
    auto result = filamat::parseForIncludes(code);

    EXPECT_EQ(1, result.size());
    EXPECT_STREQ("", result[0].name.c_str_safe());
    EXPECT_EQ(0, result[0].startPosition);
    EXPECT_EQ(11, result[0].length);
    EXPECT_EQ(1, result[0].line);
}

TEST(IncludeParser, Whitepsace) {
    utils::CString code("  #include      \"foobarbaz.h\"");
    auto result = filamat::parseForIncludes(code);

    EXPECT_EQ(1, result.size());
    EXPECT_STREQ("foobarbaz.h", result[0].name.c_str());
    EXPECT_EQ(2, result[0].startPosition);
    EXPECT_EQ(27, result[0].length);
    EXPECT_EQ(1, result[0].line);
}

TEST(IncludeParser, InvalidIncludes) {
    utils::CString code("#include");
    auto result = filamat::parseForIncludes(code);
    EXPECT_EQ(0, result.size());
}

TEST(IncludeParser, InvalidWithValidInclude) {
    {
        utils::CString code("#include #include \"foobar.h\"");
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(1, result.size());
        EXPECT_STREQ("foobar.h", result[0].name.c_str());
        EXPECT_EQ(9, result[0].startPosition);
        EXPECT_EQ(19, result[0].length);
        EXPECT_EQ(1, result[0].line);
    }

    {
        utils::CString code("abcdefghi #include#include#include\"foo.h\"");
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(1, result.size());
        EXPECT_STREQ("foo.h", result[0].name.c_str());
        EXPECT_EQ(26, result[0].startPosition);
        EXPECT_EQ(15, result[0].length);
        EXPECT_EQ(1, result[0].line);
    }
}

TEST(IncludeParser, LineNumbers) {
        utils::CString code("#include \"one.h\"\n#include \"two.h\"\n\n#include \"four.h\"");
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(3, result.size());
        EXPECT_EQ(1, result[0].line);
        EXPECT_EQ(2, result[1].line);
        EXPECT_EQ(4, result[2].line);
}

TEST(IncludeParser, IncludeWithinStarComment) {
    {
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(0, result.size());
    }
    {
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(1, result.size());
        EXPECT_STREQ("foobar.h", result[0].name.c_str());
        EXPECT_EQ(8, result[0].startPosition);
        EXPECT_EQ(19, result[0].length);
        EXPECT_EQ(1, result[0].line);
    }
}

TEST(IncludeParser, IncludeWithinSlashComment) {
    {
        utils::CString code(R"(// #include "foobar.h")");
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(0, result.size());
    }
    {
        utils::CString code(R"(
        //
        // #include "foobar.h"
        )");
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(0, result.size());
    }
    {
        utils::CString code(R"(
        //
        // // #include "foobar.h"

        )");
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(0, result.size());
    }
    {
        utils::CString code("// comment\n#include \"foobar.h\"");
        auto result = filamat::parseForIncludes(code);
        EXPECT_EQ(1, result.size());
        EXPECT_STREQ("foobar.h", result[0].name.c_str());
        EXPECT_EQ(11, result[0].startPosition);
        EXPECT_EQ(19, result[0].length);
        EXPECT_EQ(2, result[0].line);
    }
}

TEST(IncludeParser, IncludeWithinBothSlashStarComments) {
    {
        utils::CString code(R"(
        // none of these are valid includes:
        // #include "foobar.h"
