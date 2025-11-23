#include <time.h>

#include "GameManager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Clock.h"

namespace df {

    GameManager::GameManager() {
        setType("GameManager");
        m_game_over = false;
        m_frame_time = FRAME_TIME_DEFAULT;
        m_step_count = 0;
    }

    GameManager::~GameManager() {
        shutDown();
    }

    int GameManager::startUp() {
        Manager::startUp(); // Call base class method to set m_is_started to true.
        LM.startUp();
        WM.startUp();

        LM.writeLog("DF: GameManager started.");
        return 0;
    }

    void GameManager::shutDown() {
        setGameOver(false); // To indicate to other game objects.

        LM.writeLog("DF: GameManager shut down.");

        WM.shutDown();
        LM.shutDown();
        Manager::shutDown();
    }

    void GameManager::run() {
        Clock clock = Clock();
        long long loop_time;
        long long actual_sleep_time;
        long long adjust_time = 0;
        long long frame_time_us = getFrameTime() * 1'000; // ms -> us

        LM.writeLog("DF: Game is running.");

        while(!getGameOver()) {

            clock.delta(); // Mark loop start.

            // === GAME LOGIC ====================================================
            // Get input
            // Update world
            // Render
            // Swap buffer
            // ===================================================================

            // Time doing game logic.
            loop_time = clock.split(); // Microseconds.

            long long intended_sleep_us = frame_time_us - loop_time - adjust_time;

            if  (intended_sleep_us < 0)
                intended_sleep_us = 0;

            // Convert microseconds to timespec
            struct timespec ts;
            ts.tv_sec = intended_sleep_us / 1'000'000;
            ts.tv_nsec = (intended_sleep_us % 1'000'000) * 1'000;

            clock.delta(); // Reset before sleeping.

            nanosleep(&ts, NULL);

            // Time actually slept
            actual_sleep_time = clock.split(); // Microseconds.

            // Adjust for next frame.
            adjust_time = actual_sleep_time - intended_sleep_us;

            if (adjust_time < 0)
                adjust_time = 0;

            m_step_count++; // Incrementing the game step count.
        }

    }

    GameManager &GameManager::getInstance() {
        static GameManager instance;
        return instance;
    }

    void GameManager::setGameOver(bool new_game_over) {
        m_game_over = new_game_over;
    }

    bool GameManager::getGameOver() const {
        return m_game_over;
    }

    int GameManager::getFrameTime() const {
        return m_frame_time;
    }

    int GameManager::getStepCount() const {
        return m_step_count;
    }
}
