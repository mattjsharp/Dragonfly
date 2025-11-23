#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "Manager.h"

// Macro to get the singleton instance of GameManager
#define GM df::GameManager::getInstance()

namespace df {

// Default frame time (game loop time) in milliseconds (33 ms == 30 f/s).
const int FRAME_TIME_DEFAULT = 33;

class GameManager : public Manager {
private:
    GameManager();                          // Private since singleton.
    GameManager(GameManager const&);        // Don't allow copy.
    void operator=(GameManager const&);     // Don't allow assignment.

    bool m_game_over;         // True, then game loop should stop.
    int m_frame_time;         // Target time per game loop, in milliseconds.
    int m_step_count;         // Count of game loop iterations.

public:
    // Shut down GameManager services
    ~GameManager() override;

    // Get the singleton instance of the GameManager.
    static GameManager &getInstance();

    // Startup all GameManager services.
    int startUp() override;

    // Shut down GameManager services.
    void shutDown() override;

    // Run game loop.
    void run();

    // Set game over status to indicated value.
    // If true (default), will stop game loop.
    void setGameOver(bool new_game_over=true);

    // Get game over status.
    bool getGameOver() const;

    // Return frame time.
    // Frame time is target time for game loop, in milliseconds.
    int getFrameTime() const;

    // Return game loop step count.
    int getStepCount() const;
};

}

#endif // __GAME_MANAGER_H__
