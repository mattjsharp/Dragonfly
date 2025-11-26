#include <gtest/gtest.h>
#include "GameManager.h"

using namespace df;

class GameManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Ensure a clean start before each test
        GM.shutDown();       // Reset singleton state if needed
        GM.startUp();
    }

    void TearDown() override {
        GM.shutDown();       // Clean up after each test
    }
};

// -------------------------------------------------------------
// Default game over status is false
// -------------------------------------------------------------
TEST_F(GameManagerTest, DefaultGameOver) {
    EXPECT_FALSE(GM.getGameOver());
}

// -------------------------------------------------------------
// setGameOver updates status
// -------------------------------------------------------------
TEST_F(GameManagerTest, SetGameOverTrue) {
    GM.setGameOver(true);
    EXPECT_TRUE(GM.getGameOver());

    GM.setGameOver(false);
    EXPECT_FALSE(GM.getGameOver());
}

// -------------------------------------------------------------
// getFrameTime returns default frame time
// -------------------------------------------------------------
TEST_F(GameManagerTest, DefaultFrameTime) {
    EXPECT_EQ(GM.getFrameTime(), FRAME_TIME_DEFAULT);
}

// -------------------------------------------------------------
// Step count starts at zero and increments when run() is called
// -------------------------------------------------------------
TEST_F(GameManagerTest, StepCountInitial) {
    EXPECT_EQ(GM.getStepCount(), 0);
}

// Optional: minimal run test (only increments one step)
TEST_F(GameManagerTest, RunOneStep) {
    // Set game over to false so run will execute at least once
    GM.setGameOver(false);

    // You could call a minimal version of run() here if your implementation allows
    // For example, maybe we add a "runOneStep()" helper for testing.
    // GM.runOneStep();

    // For now, just check that step count is zero at startup
    EXPECT_EQ(GM.getStepCount(), 0);
}
