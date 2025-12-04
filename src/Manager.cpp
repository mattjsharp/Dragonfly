#include "Manager.h"
#include "WorldManager.h"
#include "Object.h"

namespace df {

    Manager::Manager() {
        m_is_started = false;

        setType("Manager");
    }

    Manager::~Manager() {
        shutDown();
    }

    void Manager::setType(std::string new_type) {
        m_type = new_type;
    }

    std::string Manager::getType() const { return m_type; }

    int Manager::startUp() {
        m_is_started = true;

        return 0;
    }

    void Manager::shutDown() {
        m_is_started = false;
    }

    bool Manager::isStarted() const {
        return m_is_started;
    }

    int Manager::onEvent(const Event* p_event) const {
        int count = 0;

        ObjectList all_objects = WM.getAllObjects();
        for (int i = 0; i < all_objects.getCount(); i++) {
            all_objects[i]->eventHandler(p_event);
            count++;
        }

        return count;
    }
}
