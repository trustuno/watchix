#include "core/event_manager/event_manager.h"
#include "event_manager/event_id.h"
#include <iostream>

#include "version.h"

void print_version() {
    printf("WatchiX Agent Version: %d.%d.%d(%s)\n", WATCHIX_MAJOR, WATCHIX_MINOR, WATCHIX_HOTFIX, WATCHIX_BUILD_ID);
}

/**
 * @brief Simple test function to print received event payload.
 * @param payload The received event data.
 */
void TestCallback(const std::string& payload) {
    std::cout << "Callback received payload @: " << payload << std::endl;
}

/**
 * @brief Main function to test EventManager.
 */
int main() {

    print_version();

    EventManager em;

    em.Start();

    Subscriber testSub;
    testSub.commType = CommunicationType::FUNCTION_CALLBACK;
    testSub.address = "TestPlugin";
    testSub.callback = TestCallback;

    // Example event ID (group 0x02 << 9 | 1)
    uint32_t eventID = PUBLIC__LOGGER_EVENT__LOGGER_EVENT_INFO;

    em.RegisterSubscriber(eventID, testSub);
    em.RegisterSubscriber(PUBLIC__SYSTEM_EVENT__SYSTEM_EVENT_HEARTBEAT, testSub);

    em.PublishEvent(eventID, "Test event data.");

    while(1)
    {
        std::this_thread::sleep_for(std::chrono::seconds(7));
        em.PublishEvent(eventID, "Test event data..");
    }
    

    em.Stop();

    return 0;
}
