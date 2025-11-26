#include "WorldManager.h"
#include "Object.h"

namespace df {

    WorldManager::WorldManager() {
        setType("WorldManager");
        m_updates = ObjectList();
        m_deletions = ObjectList();
    }

    WorldManager &WorldManager::getInstance() {
        static WorldManager instance;
        return instance;
    }

    int WorldManager::startUp() {
        Manager::startUp();  // Call base class method to set m_is_started to true.

        return 0;
    }

    void WorldManager::shutDown() {
        // Delete all game objects.
        ObjectList ol = m_updates;  // Copy list so can delete during iteration.
        for (int i = 0; i < ol.getCount(); i++) {
            delete ol[i];
        }

        Manager::shutDown();  // Call base class method to set m_is_started to false.
    }

    int WorldManager::insertObject(Object* p_o) {
        return m_updates.insert(p_o);
    }

    int WorldManager::removeObject(Object* p_o) {
        return m_updates.remove(p_o);
    }

    ObjectList WorldManager::getAllObjects() const {
        return m_updates;
    }

    ObjectList WorldManager::objectsOfType(std::string type) {
        ObjectList list = ObjectList();

        for (int i = 0; i < m_updates.getCount(); i++) {
            if (m_updates[i]->getType() == type) {
                list.insert(m_updates[i]);
            }
        }

        return list;
    }

    void WorldManager::update() {
        // Delete all marked Objects.
        for (int i = 0; i < m_deletions.getCount(); i++) {
            delete m_deletions[i];
        }

        // Clear list for next update phase.
        m_deletions.clear();
    }

    int WorldManager::markForDelete(Object* p_o) {
        // Object might already have been marked, so only add once.
        for (int i = 0; i < m_deletions.getCount(); i++) {
            if (m_deletions[i] == p_o) {    // Object already in list.
                return 0;                   // This is still "ok".
            }
        }

        // Object not in list, so add.
        return m_deletions.insert(p_o);
    }

    void WorldManager::draw() {
        for (int i = 0; i < m_updates.getCount(); i++) {
            m_updates[i]->draw();
        }
    }
}
