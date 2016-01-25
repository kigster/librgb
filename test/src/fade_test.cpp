//
// Created by Konstantin Gredeskoul on 1/23/16.
//

#include "gtest/gtest.h"
#include "macros_color_test.h"
#include "Effect.h"


TEST(fade_effect, set_color) {
    fade = FadeEffect(purple, purple, 200);
    EXPECT_EQ_COLORS(fade.get_color(), purple);

    wait_for(fade, 10);
    EXPECT_EQ_COLORS(fade.get_color(), purple);
}

TEST(fade_effect, fade_same_colors) {
    fade = FadeEffect(purple, purple, 100);
    EXPECT_EQ_COLORS(fade.get_color(), purple);
    wait_for(fade, 90);
    EXPECT_EQ_COLORS(fade.get_color(), purple);
}

typedef struct {
    color_t x;
    color_t y;
    float   ratio;
    color_t result;
} ConvergeExpecation;


TEST(fade_effect, converge) {
    float              r     = 0.5;
    ConvergeExpecation ces[] = {
            {80, 90, 0.5, 85},
            {0, 255, 0.5, 127},
            {50, 20, 0.3, 41},
            {0x20, 0x10, r, (color_t) (0x20 - r * (0x20 - 0x10))},
            {0x30, 0x00, r, (color_t) (0x30 - r * (0x30 - 0x00))},
            {0xFF, 0xE0, r, (color_t) (0xFF - r * (0xFF - 0xE0))},
    };

    for (int i = 0; i < sizeof(ces) / sizeof(ConvergeExpecation); i++) {
        EXPECT_CONVERGENCE(ces[i]);
    }
}

TEST(fade_effect, tick_100ms) {
    fade        = FadeEffect(RGB(0x2030FF), RGB(0x1000E0), 200);
    RGB halfWay = RGB(0x1818EF);
    EXPECT_FLOAT_EQ(0.5, fade.progressAt(fade.get_startTime() + fade.get_duration() / 2));
//    wait_for(fade, 103);
//    EXPECT_EQ_COLORS(fade.get_color(), halfWay);
}
