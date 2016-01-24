#include <iostream>
#include <ctime>

#include "RGBColor.h"
#include "RGBPixel.h"
#include "arduino-emulation.h"
using namespace std;

RGBPixel pixel;

#define DELAY_MS 8000
#define C1       0xff5000
#define C2       0x8020ff

rgb_color_t color;
uint8_t mode = 0;
uint32_t prevTime, pauseTime = 0;

void log() {
    printf("Mode = %d, color is now %#08x, pixel.getColor() is %#08x\n", mode, color, pixel.getColor().getValue());
}

void setup() {
    startTime = std::clock();
    color = C1;
    log();
    pixel.fade(C1, C2, DELAY_MS);
    color = pixel.getColor().getValue();
    log();
}

void loop() {
    uint8_t i;
    uint32_t t;

    pixel.tick();

    t = millis();

    if (t - pauseTime >= 200) {
        color = pixel.getColor().getValue();
        pauseTime = t;
        log();
    }

    if ((t - prevTime) > DELAY_MS) {
        mode++;
        if (mode == 1) {
            pixel.fade(C2, C1, DELAY_MS);
        } else if (mode == 2) {
            mode = 0;
            pixel.fade(C1, C2, DELAY_MS);
        }
        prevTime = t;
    }
    if (millis() > 30*1000)
        exit(0);
}

int main() {
    setup();

    while (true) {
        loop();
    }

}
