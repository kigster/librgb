//
// Created by Konstantin Gredeskoul on 1/23/16.
//

#include "gtest/gtest.h"
#include "macros_color_test.h"

TEST(rgb_pixel, set_color) {
    pixel.setColor(purple);

    EXPECT_EQ_COLORS(pixel.getColor(), purple);
    wait_for(10);
    EXPECT_EQ_COLORS(pixel.getColor(), purple);
}

TEST(rgb_pixel, fade_same_colors) {
    pixel.fade(purple, purple, 100);
    EXPECT_EQ_COLORS(pixel.getColor(), purple);
    wait_for(90);
    EXPECT_EQ_COLORS(pixel.getColor(), purple);
}

TEST(rgb_pixel, tick_100ms) {
    pixel.fade(purple, orange, 200);
    wait_for(100);
    RGBColor dark_grey = (orange - purple) / 2;
    EXPECT_EQ_COLORS(dark_grey, pixel.getColor());
}
