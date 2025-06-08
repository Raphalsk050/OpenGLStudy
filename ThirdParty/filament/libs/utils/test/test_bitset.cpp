
#include <gtest/gtest.h>

#include "third_party/filament/libs/utils/include/utils/bitset.h"

using namespace utils;

TEST(BitSetTest, bitset256) {
    bitset256 b;

    EXPECT_EQ(0, b.count());
    EXPECT_TRUE(b == b);

    b.set(0);
    EXPECT_EQ(1, b.count());
    EXPECT_TRUE(b == b);

    b.set(64);
    EXPECT_EQ(2, b.count());
    EXPECT_TRUE(b == b);

    b.set(128);
    EXPECT_EQ(3, b.count());
    EXPECT_TRUE(b == b);

    b.set(192);
    EXPECT_EQ(4, b.count());
    EXPECT_TRUE(b == b);

    b = ~b;
    EXPECT_EQ(252, b.count());
    EXPECT_TRUE(b == b);

    EXPECT_TRUE(b.any());
    EXPECT_TRUE((b & ~b).none());
    EXPECT_TRUE((b | ~b).all());
}

TEST(BitSetTest, LargeBitset) {
    bitset<uint64_t, 2 * 31> b;
    b = ~b;
    EXPECT_EQ(64 * 2 * 31, b.count());
}

TEST(BitSetTest, SetBit) {
    bitset8 b;
    b.set(1, true);
    EXPECT_TRUE(b.test(1));
    b.set(1, false);
    EXPECT_FALSE(b.test(1));
}

TEST(BitSetTest, TestOperator) {
    bitset8 b;
    b.set(1, true);
    EXPECT_TRUE(b[1]);
    b.set(1, false);
    EXPECT_FALSE(b[1]);
}

TEST(BitSetTest, Count) {
    bitset8 b;
    EXPECT_EQ(0, b.count());
    b.set(1, true);
    b.set(3, true);
    b.set(4, true);
    EXPECT_EQ(3, b.count());
}

TEST(BitSetTest, Reset) {
    bitset8 b;
    b.set(1, true);
    b.set(3, true);
    b.set(4, true);
    b.reset();
    EXPECT_TRUE(b.none());
}

TEST(BitSetTest, AnyBit) {
    bitset8 b;
    EXPECT_FALSE(b.any());
    b.set(1, true);
    EXPECT_TRUE(b.any());
}

TEST(BitSetTest, None) {
    bitset8 b;
    EXPECT_TRUE(b.none());
    b.set(1, true);
    b.reset();
    EXPECT_TRUE(b.none());
}

TEST(BitSetTest, All) {
    bitset8 b;
    EXPECT_FALSE(b.all());
    b.set(1, true);
    EXPECT_FALSE(b.all());
    b.set(0, true);
    b.set(2, true);
    b.set(3, true);
    b.set(4, true);
    b.set(5, true);
    b.set(6, true);
    b.set(7, true);
    EXPECT_TRUE(b.all());
}

TEST(BitSetTest, FlipBit) {
    bitset8 b;
    b.flip(1);
    EXPECT_TRUE(b.test(1));
    b.flip(1);
    EXPECT_FALSE(b.test(1));
}

TEST(BitSetTest, SetUnset) {
    bitset8 b;
    b.set(1);
    EXPECT_TRUE(b.test(1));
    b.unset(1);
    EXPECT_FALSE(b.test(1));
}

TEST(BitSetTest, AndOperator) {
    bitset8 b1;
    b1.set(1);

    bitset8 b2;
    b2.set(2);

    bitset8 b3 = b1 & b2;
    EXPECT_FALSE(b3[1]);
    EXPECT_FALSE(b3[2]);
    EXPECT_TRUE(b3.none());

    b2.reset();
    b2.set(1);

    b3 = b1 & b2;
    EXPECT_TRUE(b3[1]);

    b1 &= b2;
    EXPECT_EQ(b3, b1);
}

TEST(BitSetTest, OrOperator) {
    bitset8 b1;
    b1.set(1);

    bitset8 b2;
    b2.set(2);

    bitset8 b3 = b1 | b2;
    EXPECT_TRUE(b3[1]);
    EXPECT_TRUE(b3[2]);

    b1 |= b2;
    EXPECT_EQ(b3, b1);
}

TEST(BitSetTest, XorOperator) {
    bitset8 b1;
    b1.set(1);

    bitset8 b2;
    b2.set(2);

    bitset8 b3 = b1 ^ b2;
    EXPECT_TRUE(b3[1]);
    EXPECT_TRUE(b3[2]);

    b2.reset();
    b2.set(1);

    b3 = b1 ^ b2;
    EXPECT_FALSE(b3[1]);
    EXPECT_FALSE(b3[2]);

    b1 ^= b2;
    EXPECT_EQ(b3, b1);
}

TEST(BitSetTest, NotOperator) {
    bitset8 b1;
    b1.set(1);

    bitset8 b3 = ~b1;
    EXPECT_FALSE(b3[1]);
    EXPECT_TRUE(b3[0]);
    EXPECT_TRUE(b3[2]);
}
