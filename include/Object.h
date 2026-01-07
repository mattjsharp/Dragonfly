#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>

#include "Vector.h"

namespace df {

enum Solidness {
    HARD,       // Object causes collisions and impedes.
    SOFT,       // Object causes collisions, but doesn't impede.
    SPECTRAL    // Object doesn't cause collisions.
};

// Forward declarations.
class Event;

class Object {
private:
    int m_id;               // Unique game engine defined identifier.
    int m_altitude;         // 0 to MAX supported (lower drawn first).
    std::string m_type;     // Game programmer defined type.
    Vector m_position;      // Position in game world.
    Vector m_direction;     // Direction vector.
    float m_speed;          // Object speed in direction.
    Solidness m_solidness;  // Solidness of object.

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

    // Set altitude of Object, with checks for range (0, MAX_ALTITUDE).
    // Return 0 if ok, else -1.
    int setAltitude(int new_altitude);

    // Return altitude of Object.
    int getAltitude() const;

    // Get position of Object.
    Vector getPosition() const;

    // Handle event (default is to ignore everything).
    // Return 0 if ignored, else 1 if handled.
    virtual int eventHandler(const Event* p_e);

    // Draws object to the display.
    virtual int draw();

    // Set speed of Object.
    void setSpeed(float speed);

    // Get speed of Object.
    float getSpeed() const;

    // Set direction of Object.
    void setDirection(Vector new_direction);

    // Get direction of Object.
    Vector getDirection() const;

    // Set direction and speed of Object.
    void setVelocity(Vector new_velocity);

    // Get velocity of Object based on direction and speed.
    Vector getVelocity() const;

    // Predict Object position based on speed and direction.
    // Return predicted position.
    Vector predictPosition();

    // Return true if Object is HARD or Soft.
    // Else false.
    bool isSolid() const;

    // Set object solidness, which checks for consistency.
    // Return 0 if ok, else -1.
    int setSolidness(Solidness new_solid);

    // Return object solidness.
    Solidness getSolidness() const;
};

}

#endif // __OBJECT_H__
