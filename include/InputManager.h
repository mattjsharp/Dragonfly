#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Manager.h"

// Get singleton instance of InputManager.
#define IM df::InputManager::getInstance()

namespace df {

class InputManager : public Manager {
private:
    InputManager();                         // Private (a singleton).
    InputManager(InputManager const&);      // Don't allow copy.
    void operator=(InputManager const&);    // Don't allow assignment.

public:
    // Get the one and only instance of the InputManager.
    static InputManager &getInstance();

    // Get window ready to capture input.
    // Return 0 if ok, else -1.
    int startUp() override;

    // Revert back to normal window mode.
    void shutDown() override;

    // Get input from the keyboard and mouse.
    // Pass event along to all Objects.
    void getInput() const;
};

}

#endif //__INPUT_MANAGER_H__
