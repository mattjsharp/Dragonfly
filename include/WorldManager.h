#ifndef __WORLD_MANAGER__
#define __WORLD_MANAGER__

#include "Manager.h"
#include "ObjectList.h"

// Macro to get the singleton instance of WorldManager
#define WM df::WorldManager::getInstance()

namespace df {

// Forward declarations.
class ObjectList;

class WorldManager : public Manager {
private:
    WorldManager();     // Private (a singleton).
    WorldManager(WorldManager const&);      // Don't allow copy.
    void operator=(WorldManager const&);    // Don't allow assignment.

    ObjectList m_updates;       // All Objects in world to update.
    ObjectList m_deletions;     // All Objects in world to delete.

public:
    // Get the one and only instance of the WorldManager.
    static WorldManager &getInstance();

    // Startup game world (initialize everything to empty).
    // Return 0.
    int startUp() override;

    // Shutdown game world (delete all game world Objects).
    void shutDown() override;

    // Insert Object into world. Return 0 if ok, else -1.
    int insertObject(Object* p_o);

    // Remove Object from world. Return 0 if ok, else -1.
    int removeObject(Object* p_o);

    // Return list of all Object in world.
    ObjectList getAllObjects() const;

    // Return list of all Object in world matching type.
    ObjectList objectsOfType(std::string type);

    // Update world.
    // Delete Objects marked for deletion.
    void update();

    // Indicate Object is to be delete at end of current game loop.
    // Return 0 if ok, else -1.
    int markForDelete(Object* p_o);
};

}

#endif // __WORLD_MANAGER__
