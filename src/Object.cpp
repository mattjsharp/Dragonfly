#include "Object.h"
#include "WorldManager.h"

namespace df {
    // Construct Object. Set default parameters and
    // add to game world (WorldManager).
    Object::Object() {
        static int new_id = 0;
        m_altitude = MAX_ALTITUDE / 2;
        m_id = new_id++;
        m_position = Vector();

        setType("Object");

        // Add self to game world.
        WM.insertObject(this);
    }

    // Destroy Object.
    // Remove from game world (WorldManager).
    Object::~Object() {
        // Remove self from game world.
        WM.removeObject(this);
    }

    void Object::setId(int new_id) {
        m_id = new_id;
    }

    int Object::getId() const { return m_id; }

    void Object::setType(std::string new_type) {
        m_type = new_type;
    }

    std::string Object::getType() const { return m_type; }

    void Object::setPosition(Vector new_pos) {
        m_position = new_pos;
    }

    Vector Object::getPosition() const { return m_position; }

    int Object::setAltitude(int new_altitude) {
        if (new_altitude < 0 || new_altitude > MAX_ALTITUDE)
            return -1;

        m_altitude = new_altitude;

        return 0;
    }

    int Object::getAltitude() const { return m_altitude; }

    int Object::eventHandler(const Event* p_e) { return 0; }

    int Object::draw() { return 0; }

    void Object::setSpeed(float speed) { m_speed = speed; }

    float Object::getSpeed() const { return m_speed; }

    void Object::setDirection(Vector new_direction) {
        m_direction = new_direction;
    }

    Vector Object::getDirection() const { return m_direction; }

    void Object::setVelocity(Vector new_velocity) {
        // Set speed and direction based on velocity.
        m_speed = new_velocity.getMagnitude();
        new_velocity.normalize();
        m_direction = new_velocity;
    }

    Vector Object::getVelocity() const {
        // Set velocity based on speed and direction.
        Vector velocity = m_direction;
        velocity.scale(m_speed);
        
        return velocity;
    }

    Vector Object::predictPosition() {
        // Add velocity to position.
        Vector new_pos = m_position + getVelocity();

        // Return new position.
        return new_pos;
    }

    bool Object::isSolid() const {
        switch (m_solidness) {
            case HARD:
            case SOFT:
                return true;
        }
        return false;
    }

    int Object::setSolidness(Solidness new_solid) {
        switch (m_solidness) {
            case HARD:
            case SOFT:
                m_solidness = new_solid;
                return 0;
        }
        return -1;
    }

    Solidness Object::getSolidness() const { return m_solidness; }
}
