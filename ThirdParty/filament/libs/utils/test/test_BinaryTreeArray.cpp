
#include <gtest/gtest.h>

#include "third_party/filament/libs/utils/include/utils/BinaryTreeArray.h"

using namespace utils;

TEST(BinaryTreeArray, basic) {


    struct Node {
        size_t index = 0;
        size_t next = 0;
        bool visited = false;
    };
    Node array[256];

    BinaryTreeArray::traverse(1,
            [&array](size_t index, size_t col, size_t next) {
                array[index] = Node{ index, next, true };
            },
            [&array](size_t index, size_t l, size_t r, size_t next) {
                EXPECT_TRUE(array[l].visited);
                EXPECT_TRUE(array[r].visited);
                array[index] = Node{ index, next };
            });

    EXPECT_EQ(0, array[0].index);
    EXPECT_EQ(1, array[0].next);


    BinaryTreeArray::traverse(2,
            [&array](size_t index, size_t col, size_t next) {
                array[index] = Node{ index, next };
            },
            [&array](size_t index, size_t l, size_t r, size_t next) {
                array[index] = Node{ index, next };
            });

    EXPECT_EQ(0, array[0].index);
    EXPECT_EQ(3, array[0].next);

        EXPECT_EQ(1, array[1].index);
        EXPECT_EQ(2, array[1].next);

        EXPECT_EQ(2, array[2].index);
        EXPECT_EQ(3, array[2].next);


    BinaryTreeArray::traverse(3,
            [&array](size_t index, size_t col, size_t next) {
                array[index] = Node{ index, next };
            },
            [&array](size_t index, size_t l, size_t r, size_t next) {
                array[index] = Node{ index, next };
            });

    EXPECT_EQ(0, array[0].index);
    EXPECT_EQ(7, array[0].next);

        EXPECT_EQ(1, array[1].index);
        EXPECT_EQ(4, array[1].next);

            EXPECT_EQ(2, array[2].index);
            EXPECT_EQ(3, array[2].next);

            EXPECT_EQ(3, array[3].index);
            EXPECT_EQ(4, array[3].next);

        EXPECT_EQ(4, array[4].index);
        EXPECT_EQ(7, array[4].next);

            EXPECT_EQ(5, array[5].index);
            EXPECT_EQ(6, array[5].next);

            EXPECT_EQ(6, array[6].index);
            EXPECT_EQ(7, array[6].next);


    BinaryTreeArray::traverse(4,
            [&array](size_t index, size_t col, size_t next) {
                array[index] = Node{ index, next };
            },
            [&array](size_t index, size_t l, size_t r, size_t next) {
                array[index] = Node{ index, next };
            });

    EXPECT_EQ(0, array[0].index);
    EXPECT_EQ(15, array[0].next);

        EXPECT_EQ(1, array[1].index);
        EXPECT_EQ(8, array[1].next);

            EXPECT_EQ(2, array[2].index);
            EXPECT_EQ(5, array[2].next);

                EXPECT_EQ(3, array[3].index);
                EXPECT_EQ(4, array[3].next);

                EXPECT_EQ(4, array[4].index);
                EXPECT_EQ(5, array[4].next);

            EXPECT_EQ(5, array[5].index);
            EXPECT_EQ(8, array[5].next);

                EXPECT_EQ(6, array[6].index);
                EXPECT_EQ(7, array[6].next);

                EXPECT_EQ(7, array[7].index);
                EXPECT_EQ(8, array[7].next);

        EXPECT_EQ(8, array[8].index);
        EXPECT_EQ(15, array[8].next);

            EXPECT_EQ(9, array[9].index);
            EXPECT_EQ(12, array[9].next);

                EXPECT_EQ(10, array[10].index);
                EXPECT_EQ(11, array[10].next);

                EXPECT_EQ(11, array[11].index);
                EXPECT_EQ(12, array[11].next);

            EXPECT_EQ(12, array[12].index);
            EXPECT_EQ(15, array[12].next);

                EXPECT_EQ(13, array[13].index);
                EXPECT_EQ(14, array[13].next);

                EXPECT_EQ(14, array[14].index);
                EXPECT_EQ(15, array[14].next);

}

