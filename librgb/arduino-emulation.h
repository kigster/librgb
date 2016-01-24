//
// Created by Konstantin Gredeskoul on 1/23/16.
//


#ifndef COLORVERIFIER_MILLIS_H
#define COLORVERIFIER_MILLIS_H

#include <ctime>

static std::clock_t startTime;

static long millis() {
    return (std::clock() - startTime) / (double)(CLOCKS_PER_SEC / 1000);
}

#endif //COLORVERIFIER_MILLIS_H
