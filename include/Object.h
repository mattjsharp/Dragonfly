#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

#include "Vector.h"
#include "Event.h"

namespace df {

class Object {
private:
    int m_id;               // Unique game engine defined identifier.
    std::string m_type;     // Game programmer defined type.
    Vector m_position;      // Position in game world.

public:
    // Construct Object. Set default parameters and
    // add to game world (WorldManager).
    Object();

    // Destroy Object.
    // Remove from game world (WorldManager).
    virtual ~Object();

    // Set Object id.
    void setId(int new_id);

    // Get Object id.
    int getId() const;

    // Set type identifier of Object.
    void setType(std::string new_type);

    // Get type identifier of Object.
    std::string getType() const;

    // Set position of Object.
    void setPosition(Vector new_pos);

    // Get position of Object.
    Vector getPosition() const;

    // Handle event (default is to ignore everything).
    // Return 0 if ignored, else 1 if handled.
    virtual int eventHandler(const Event* p_e);
};

}

#endif // __OBJECT_H__
