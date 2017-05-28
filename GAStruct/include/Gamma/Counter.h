//
// Created by Deiwid on 2017-04-04.
//

#ifndef GAMMA_COUNTER_H
#define GAMMA_COUNTER_H

#include <cstdint>
#include <mutex>

class Counter {
private:
    volatile uint64_t num = 0;
    std::mutex mutex;
public:
    uint64_t next() {
        std::lock_guard<std::mutex> guard(mutex);
        return ++num;
    }
};

#endif //GAMMA_COUNTER_H
