#include "Manager.h"

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

    std::string Manager::getType() const {
        return m_type;
    }

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
}
