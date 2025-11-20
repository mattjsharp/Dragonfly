#ifndef __OBJECT_LIST_H__
#define __OBJECT_LIST_H__

#include <stdexcept>

#include "Object.h"

namespace df {

const int MAX_OBJECTS = 1000;

class ObjectList {
private:
    int m_count;                    // Count of objects in list.
    Object* m_p_obj[MAX_OBJECTS];   // Array of pointers to objects.

public:
    // Default constructor.
    ObjectList();

    // Insert object pointer in list.
    // Return 0 if ok, else -1.
    int insert(Object* p_o);

    // Remove object pointer from list.
    // Return 0 if found, else -1.
    int remove(Object* p_o);

    // Clear list (setting count to 0).
    void clear();

    // Return count of number of objects in list.
    int getCount() const;

    // Return true if list is empty, else false.
    bool isEmpty() const;

    // Return true if list is full, else false.
    bool isFull() const;

    // Index into list.
    Object* operator[](int index);

    // TODO
    // - Make list dynamic
    // - Add + operator
    // - Create Iterator Class
};

}

#endif // __OBJECT_LIST_H__
