#include "Object.h"

namespace df {
    Object::Object() {
        static int new_id = 0;
        setId(new_id++);
        setType("Object");
        setPosition(Vector());
    }

    Object::~Object() {}

    void Object::setId(int new_id) {
        m_id = new_id;
    }

    int Object::getId() const {
        return m_id;
    }

    void Object::setType(std::string new_type) {
        m_type = new_type;
    }

    std::string Object::getType() const {
        return m_type;
    }

    void Object::setPosition(Vector new_pos) {
        m_position = new_pos;
    }

    Vector Object::getPosition() const {
        return m_position;
    }

    int Object::eventHandler(const Event* p_e) {
        return 0;
    }
}
