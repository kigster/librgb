#include <iostream>
#include <ctime>

#include "RGBColor.h"
#include "FadeEffect.h"
#include "arduino-emulation.h"

using namespace std;

#define DELAY_MS 8000
#define C1       0xff5000
#define C2       0x8020ff

FadeEffect fade(C1, C2, DELAY_MS);

rgb_color_t color;
uint8_t mode = 0;
uint32_t prevTime, pauseTime = 0;

void log() {
    printf("Mode = %d, color is now %#08x, fade.getColor() is %#08x\n", mode, color, fade.getColor().getValue());
}

void setup() {
    startTime = std::clock();
    color = C1;
    log();
    color = fade.getColor().getValue();
    log();
}

void loop() {
    uint8_t i;
    uint32_t t;

    fade.tick();

    t = millis();

    if (t - pauseTime >= 200) {
        color = fade.getColor().getValue();
        pauseTime = t;
        log();
    }

    if ((t - prevTime) > DELAY_MS) {
        mode++;
        if (mode == 1) {
            fade.restart(C2, C1, DELAY_MS);
        } else if (mode == 2) {
            mode = 0;
            fade.restart(C1, C2, DELAY_MS);
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
