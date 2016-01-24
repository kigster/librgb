//
// Created by Konstantin Gredeskoul on 1/23/16.
//

#ifndef COLORFADER_MACROS_COLOR_TEST_H
#define COLORFADER_MACROS_COLOR_TEST_H

#include <RGBColor.h>
#include <FadeEffect.h>

#define PRINT_HEX(X,Y) printf("[%#08x] vs [%#08x]", X, Y);


static char    buf1[9] = "",
               buf2[9] = "";

#define TO_HEX(X,Y) X.getHex(Y);
#define EXPECT_EQ_COLORS(X,Y)       \
    TO_HEX(X, buf1);                \
    TO_HEX(Y, buf2);                \
    EXPECT_EQ(*buf2, *buf1);        \
    EXPECT_EQ(Y.getValue(), X.getValue());



static RGB purple = RGB(0xfe00fe);
static RGB orange = RGB(0xff6000);

static FadeEffect fade = FadeEffect(purple, orange, 200);

static void wait_for(FadeEffect effect, long ms) {
    long t1 = millis();
    while (millis() - t1 < ms) {
        effect.tick();
    }
}

#endif //COLORFADER_MACROS_COLOR_TEST_H
