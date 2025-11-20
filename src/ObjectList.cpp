#include "ObjectList.h"

namespace df {
    ObjectList::ObjectList() {
        m_count = 0;
    }

    int ObjectList::insert(Object* p_o) {
        if (m_count == MAX_OBJECTS)
            return -1;
        m_p_obj[m_count] = p_o;
        m_count++;
        return 0;
    }

    int ObjectList::remove(Object* p_o) {
        for (int i = 0; i < m_count; i++) {
            // If found swap the element to be removed with the last element
            // and decreemnt count.
            if (m_p_obj[i] == p_o) {
                m_p_obj[i] = m_p_obj[m_count -= 1];
                return 0;
            }
        }
        return -1; // If not found.
    }

    void ObjectList::clear() {
        m_count = 0;
    }

    int ObjectList::getCount() const {
        return m_count;
    }

    bool ObjectList::isEmpty() const {
        return !(m_count > 0);
    }

    bool ObjectList::isFull() const {
        return m_count >= MAX_OBJECTS;
    }

    Object* ObjectList::operator[](int index) {
        if (index >= m_count || index < 0)
            throw std::out_of_range("Invalid index!");
        return m_p_obj[index];
    }
}
