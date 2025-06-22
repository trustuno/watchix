#ifndef EVENT_LIST_H
#define EVENT_LIST_H

#include <assert.h> // For static_assert

/**
 * @file event_list.h
 * @brief List of all event groups and their events.
 */

// Event Groups (7 bits -> up to 127 groups)
enum EventGroup {
    SYSTEM_EVENT_GROUP = 0x01,
    LOGGER_EVENT_GROUP = 0x03,
    // Add more groups here

    MAX_EVENT_GROUP_COUNT
};
static_assert(MAX_EVENT_GROUP_COUNT - 1 <= 127, "Error: EVENT GROUPs can not exceed 128!");


// Events for SYSTEM_EVENT_GROUP
enum SYSTEM_EVENT {
    SYSTEM_EVENT_HEARTBEAT = 1,
    SYSTEM_EVENT_SHUTDOWN,
   // Add more system events here

    SYSTEM_EVENT_MAX_COUNT
};
static_assert(SYSTEM_EVENT_MAX_COUNT - 1 <= 255, "Error: SYSTEM_EVENT group exceeds 255 events!");


// Events for LOGGER_EVENT_GROUP
enum LOGGER_EVENT {
    LOGGER_EVENT_INFO = 1,
    LOGGER_EVENT_WARN,
    LOGGER_EVENT_ERROR,
     // Add more system events here

    LOGGER_EVENT_MAX_COUNT
};
static_assert(LOGGER_EVENT_MAX_COUNT - 1 <= 255, "Error: SYSTEM_EVENT group exceeds 255 events!");

#endif // EVENT_LIST_H
