/*
    MIT License

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.

    (c) 2015-2016 Konstantin Gredeskoul
    Created on 1/23/2016

    This file is an emulation of Arduino environment, and possibly
    other libraries, used simply to allow unit testing of the libraries.
    When the library is included in an action Arduino environment
    the contents of this file are undefined.
 */


#ifndef ARDUINO

#ifndef _ARDUINO_EMULATION_H
#define _ARDUINO_EMULATION_H

#include <sys/time.h>

static uint32_t now() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return (uint32_t) (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}
static uint32_t startTime = now();
static uint32_t millis() {
    return now() - startTime;
}

static void setup() {
}

static void loop() {

}

static int arduino_main() {
    setup();

    while (true) {
        loop();
    }

}


#endif //_ARDUINO_EMULATION_H
#else

#include <Arduino.h>

#endif // ARDUINO
