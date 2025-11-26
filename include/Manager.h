#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <string>

namespace df {

// Forward declarations.
class Event;

class Manager {
private:
    std::string m_type;     // Manager type identifier.
    bool m_is_started;      // True when started successfully.

protected:
    // Set type identifier of Manager.
    void setType(std::string new_type);

public:
    Manager();
    virtual ~Manager();

    // Get type identifier of Manager.
    std::string getType() const;

    // Startup Manager.
    // Return 0 if ok, else negative number.
    virtual int startUp();

    // Shutdown Manager.
    virtual void shutDown();

    // Return true when startUp() was executed ok, else false.
    bool isStarted() const;

    // Send event to all Objects.
    // Return count of number events sent.
    int onEvent(const Event* p_event) const;
};

}

#endif // __MANAGER_H__
