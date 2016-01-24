//
// Created by Konstantin Gredeskoul on 1/23/16.
//

#include "gtest/gtest.h"
#include "macros_color_test.h"

TEST(rgb_color, assignment) {
    RGBColor c = purple;
    EXPECT_EQ_COLORS(c, purple);
}

TEST(rgb_color, division) {
    EXPECT_EQ_COLORS((RGBColor(0xFE00FE) / 2), RGBColor(0x7F007F));
}

TEST(rgb_color, addition) {
    EXPECT_EQ_COLORS((RGBColor(0x1120F0) + RGBColor(0x44E001)), RGBColor(0x55FFF1));
}

TEST(rgb_color, addition_plus_equals) {
    RGBColor c  = RGBColor(0xFF0070);
    c += RGBColor(0x23030A);
    EXPECT_EQ_COLORS(c, RGBColor(0xFF037A));
}

TEST(rgb_color, subtraction) {
    EXPECT_EQ_COLORS((RGBColor(0x1120F0) - RGBColor(0x44E001)), RGBColor(0x0000EF));
}

TEST(rgb_color, minus_equals) {
    RGBColor c  = RGBColor(0xFF00FF);
    c -= RGBColor(0x020305);
    EXPECT_EQ_COLORS(c, RGBColor(0xFD00FA));
}
