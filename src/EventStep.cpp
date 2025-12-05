#include "EventStep.h"

namespace df {

    EventStep::EventStep() : EventStep(0) {}

    EventStep::EventStep(int init_step_count) {
        setType(STEP_EVENT);
        m_step_count = init_step_count;
    }

    void EventStep::setStepCount(int new_step_count) {
        m_step_count = new_step_count;
    }

    int EventStep::getStepCount() const { return m_step_count; }
}
