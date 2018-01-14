//
// Created by Konstantin Gredeskoul on 1/23/16.
//

#include "gtest/gtest.h"
#include "test_macros.h"

TEST(rgb_color, assignment) {
    RGB c = purple;
    EXPECT_EQ_COLORS(c, purple);
}

TEST(rgb_color, division) {
    EXPECT_EQ_COLORS((RGB(0xFE00FE) / 2), RGB(0x7F007F));
}

TEST(rgb_color, addition) {
    EXPECT_EQ_COLORS((RGB(0x1120F0) + RGB(0x44E001)), RGB(0x55FFF1));
}

TEST(rgb_color, addition_plus_equals) {
    RGB c  = RGB(0xFF0070);
    c += RGB(0x23030A);
    EXPECT_EQ_COLORS(c, RGB(0xFF037A));
}

TEST(rgb_color, subtraction) {
    EXPECT_EQ_COLORS((RGB(0x1120F0) - RGB(0x44E001)), RGB(0x0000EF));
}

TEST(rgb_color, minus_equals) {
    RGB c  = RGB(0xFF00FF);
    c -= RGB(0x020305);
    EXPECT_EQ_COLORS(c, RGB(0xFD00FA));
}

TEST(rgb_color, scaleTo) {
    RGB r1  = RGB(0xF0A020);
    RGB r2  = RGB(0xD08010);
    EXPECT_EQ_COLORS(r1.scaleTo(r2, 0.5), RGB(0xE09018));
    EXPECT_EQ_COLORS(r2.scaleTo(r1, 0.5), RGB(0xE09018));

    EXPECT_EQ_COLORS(r1.scaleTo(r2, 1), r2);
    EXPECT_EQ_COLORS(r2.scaleTo(r1, 1), r1);
}

TEST(rgb_color, converge) {
    color_t r1 = 200;
    color_t r2 = 120;

    EXPECT_EQ(160, converge(r1, r2, 0.5));
    EXPECT_EQ(140, converge(r1, r2, 0.75));

    EXPECT_EQ(180, converge(r2, r1, 0.75));
    EXPECT_EQ(199, converge(r2, r1, 0.99));
}
