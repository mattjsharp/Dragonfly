#include <gtest/gtest.h>
#include "Manager.h"

using namespace df;

// -------------------------------------------------------------
// getType() Get type identifier of Manager.
// -------------------------------------------------------------
TEST(ManagerTest, getTypeReturnsCorrectType) {
    Manager manager;
    EXPECT_EQ(manager.getType(), "Manager");
}
