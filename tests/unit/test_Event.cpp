#include <gtest/gtest.h>
#include "Event.h"

using namespace df;

class EventTest : public ::testing::Test {
protected:
    Event* e;

    void SetUp() override {
        e = new Event();
    }

    void TearDown() override {
        delete e;
    }
};

// -------------------------------------------------------------
//  Default constructor sets type to UNDEFINED_EVENT
// -------------------------------------------------------------
TEST_F(EventTest, DefaultConstructor) {
    EXPECT_EQ(e->getType(), UNDEFINED_EVENT);
}

// -------------------------------------------------------------
//  setType changes the event type
// -------------------------------------------------------------
TEST_F(EventTest, SetTypeChangesType) {
    e->setType("df::test_event");
    EXPECT_EQ(e->getType(), "df::test_event");
}

// -------------------------------------------------------------
//  Multiple setType calls update type correctly
// -------------------------------------------------------------
TEST_F(EventTest, MultipleSetTypeCalls) {
    e->setType("event_one");
    EXPECT_EQ(e->getType(), "event_one");

    e->setType("event_two");
    EXPECT_EQ(e->getType(), "event_two");
}
