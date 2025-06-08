
#include <gtest/gtest.h>

#include "GlslMinify.h"

#include <string>

using std::string;

using namespace glslminifier;

class GlslminifierTest : public testing::Test {};

TEST_F(GlslminifierTest, EmptyString) {
    EXPECT_EQ(minifyGlsl(""), "");
}

TEST_F(GlslminifierTest, GlslNoChanges) {
    std::string glsl = R"glsl("void main() { gl_FragColor = vec4(1.0); })glsl";
    EXPECT_EQ(minifyGlsl(glsl, GlslMinifyOptions::ALL), glsl);
}

TEST_F(GlslminifierTest, RemoveSlashSlashComments) {
    std::string glsl = R"glsl(
        #version 330
        void main() {// This is a comment at the end of a line.
            // This is a comment, and this whole line should be removed.
            gl_FragColor = vec4(2.0 / 4.0, 0.0, 0.0, 1.0);
            // Another comment.
        }
        // This is a comment without a trailing newline.)glsl";
    std::string expected = R"glsl(
        #version 330
        void main() {

            gl_FragColor = vec4(2.0 / 4.0, 0.0, 0.0, 1.0);

        }
)glsl";
    EXPECT_EQ(minifyGlsl(glsl, GlslMinifyOptions::STRIP_COMMENTS), expected);
}

TEST_F(GlslminifierTest, RemoveStarComments) {
    std::string glsl = R"glsl(
        #version 330
            gl_FragColor = vec4(2.0 / 4.0, 0.0, 0.0, 1.0);
