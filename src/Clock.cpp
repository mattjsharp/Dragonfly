#include <time.h>

#include "Clock.h"

namespace df {

    Clock::Clock() {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);

        // Setting to current time in microseconds
        m_previous_time = ts.tv_sec*1'000'000LL + ts.tv_nsec/1'000LL;
    }

    long long Clock::delta() {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);

        long long current_time = ts.tv_sec*1'000'000LL + ts.tv_nsec/1'000LL;
        long long elapsed_time = current_time - m_previous_time;

        m_previous_time = current_time; // Reset clock.

        return elapsed_time;
    }

    long long Clock::split() const {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);

        long long current_time = ts.tv_sec*1'000'000LL + ts.tv_nsec/1000LL;
        long long elapsed_time = current_time - m_previous_time;

        return elapsed_time;
    }

}
