#include <gtest/gtest.h>
#include <thread>       // for std::this_thread::sleep_for
#include <chrono>
#include "Clock.h"

using namespace df;
using namespace std::chrono;

class ClockTest : public ::testing::Test {
protected:
    Clock clock;
};

// -------------------------------------------------------------
// delta() returns non-negative and resets clock
// -------------------------------------------------------------
TEST_F(ClockTest, DeltaReturnsNonNegative) {
    long long d1 = clock.delta();
    EXPECT_GE(d1, 0);

    std::this_thread::sleep_for(milliseconds(10));

    long long d2 = clock.delta();
    EXPECT_GE(d2, 10000); // 10ms = 10000 microseconds
}

// -------------------------------------------------------------
// split() returns non-negative and does NOT reset clock
// -------------------------------------------------------------
TEST_F(ClockTest, SplitReturnsNonNegative) {
    std::this_thread::sleep_for(milliseconds(5));

    long long s1 = clock.split();
    EXPECT_GE(s1, 5000); // at least 5ms in microseconds

    std::this_thread::sleep_for(milliseconds(5));

    long long s2 = clock.split();
    EXPECT_GE(s2, s1); // split does not reset, elapsed increases
}

// -------------------------------------------------------------
// delta() resets clock
// -------------------------------------------------------------
TEST_F(ClockTest, DeltaResetsClock) {
    std::this_thread::sleep_for(milliseconds(5));

    long long d1 = clock.delta();
    EXPECT_GE(d1, 5000);

    std::this_thread::sleep_for(milliseconds(5));

    long long d2 = clock.delta();
    EXPECT_GE(d2, 5000); // delta resets clock, so second interval is independent
}
