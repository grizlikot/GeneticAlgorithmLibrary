//
// Created by Deiwid on 2017-04-03.
//

#ifndef GAMMA_TIMER_H
#define GAMMA_TIMER_H


#include <chrono>

#include "BuildOptions.h"

class GAMMA_LIB Timer {
private:
    std::chrono::high_resolution_clock::time_point st;
public:
    void start();
    double lap();
    double time();
};

#endif //GAMMA_TIMER_H
