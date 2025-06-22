#include "event_manager.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "event_manager/event_id.h"

/**
 * @brief EventManager constructor.
 */
EventManager::EventManager() : running_(false) {}

/**
 * @brief EventManager destructor.
 */
EventManager::~EventManager() {
    Stop();
}

/**
 * @brief Starts the EventManager's event listener and heartbeat sender.
 */
void EventManager::Start() {
    running_ = true;

    eventListenerThread_ = std::thread(&EventManager::EventListener, this);
    heartbeatThread_ = std::thread(&EventManager::SendHeartbeat, this);
}

/**
 * @brief Stops the EventManager and joins threads.
 */
void EventManager::Stop() {
    running_ = false;

    if (eventListenerThread_.joinable()) {
        eventListenerThread_.join();
    }

    if (heartbeatThread_.joinable()) {
        heartbeatThread_.join();
    }
}

/**
 * @brief Registers a subscriber to a specific event.
 */
bool EventManager::RegisterSubscriber(uint32_t eventID, const Subscriber& subscriber) {
    std::lock_guard<std::mutex> lock(mapMutex_);
    subscriptionMap_[eventID].push_back(subscriber);
    return true;
}

/**
 * @brief Deregisters a subscriber from a specific event.
 */
bool EventManager::DeregisterSubscriber(uint32_t eventID, const std::string& address) {
    std::lock_guard<std::mutex> lock(mapMutex_);
    auto& subscribers = subscriptionMap_[eventID];

    auto it = std::remove_if(subscribers.begin(), subscribers.end(),
        [&address](const Subscriber& sub) { return sub.address == address; });

    if (it != subscribers.end()) {
        subscribers.erase(it, subscribers.end());
        return true;
    }

    return false;
}

/**
 * @brief Publishes an event to all registered subscribers.
 */
void EventManager::PublishEvent(uint32_t eventID, const std::string& payload) {
    std::lock_guard<std::mutex> lock(mapMutex_);
    auto it = subscriptionMap_.find(eventID);
    if (it != subscriptionMap_.end()) {
        for (const auto& subscriber : it->second) {
            if (subscriber.commType == CommunicationType::FUNCTION_CALLBACK && subscriber.callback) {
                subscriber.callback(payload);
            } else {
                // Future: handle UNIX socket and message queue communication here.
                std::cout << "Dispatching event to subscriber at address: " << subscriber.address << std::endl;
            }
        }
    }
}

/**
 * @brief Dummy event listener loop. (To be implemented with UNIX socket later)
 */
void EventManager::EventListener() {
    while (running_) {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        // Future: Add UNIX socket listening logic here.
        // printf("check, if something there");
    }
}

/**
 * @brief Sends heartbeat event at regular intervals.
 */
void EventManager::SendHeartbeat() {
    while (running_) {
        PublishEvent(PUBLIC__SYSTEM_EVENT__SYSTEM_EVENT_HEARTBEAT, "HEARTBEAT"); // Example heartbeat event ID
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

