//
// Created by Konstantin Gredeskoul on 1/23/16.
//

#ifndef RGB_MACROS_COLOR_TEST_H
#define RGB_MACROS_COLOR_TEST_H

#include <RGBColor.h>
#include <FadeEffect.h>
#include <arduino-emulation.h>
#include "gtest/gtest.h"

static char    buf1[9] = "",
               buf2[9] = "";

#define TO_HEX(X,Y) X.hex(Y);

#define EXPECT_EQ_COLORS(X,Y)            \
    TO_HEX(X, buf1);                     \
    TO_HEX(Y, buf2);                     \
    EXPECT_STRCASEEQ(buf2, buf1);        \
    EXPECT_EQ(Y.getValue(), X.getValue());

#define EXPECT_CONVERGENCE(ce)      \
        EXPECT_EQ(converge(ce.x, ce.y, ce.ratio), ce.result)

static RGB purple = RGB(0xfe00fe);
static RGB orange = RGB(0xff6000);

static FadeEffect fade = FadeEffect(purple, orange, 200);

static void wait_for(Effect effect, long ms) {
    long t1 = millis();
    while (millis() - t1 < ms) {
        effect.tick(millis());
    }
}

#endif //RGB_MACROS_COLOR_TEST_H
