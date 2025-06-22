#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <unordered_map>
#include <vector>
#include <string>
#include <functional>
#include <mutex>
#include <thread>
#include <atomic>
#include <cstdint>

/**
 * @brief Communication types supported by the Event Manager.
 */
enum class CommunicationType {
    UNIX_SOCKET,
    MESSAGE_QUEUE,
    FUNCTION_CALLBACK
};

/**
 * @brief Subscription details for a plugin.
 */
struct Subscriber {
    CommunicationType commType;              ///< Communication mechanism
    std::string address;                     ///< UNIX socket path or message queue name
    std::function<void(const std::string&)> callback; ///< Callback for in-process communication
};

/**
 * @brief Event Manager class to handle event-based communication.
 */
class EventManager {
public:
    /**
     * @brief Constructor for EventManager.
     */
    EventManager();

    /**
     * @brief Destructor for EventManager.
     */
    ~EventManager();

    /**
     * @brief Starts the Event Manager event listener and heartbeat thread.
     */
    void Start();

    /**
     * @brief Stops the Event Manager.
     */
    void Stop();

    /**
     * @brief Registers a subscriber to a specific event.
     * @param eventID The event ID to subscribe to.
     * @param subscriber Subscriber information.
     * @return True if registration is successful.
     */
    bool RegisterSubscriber(uint32_t eventID, const Subscriber& subscriber);

    /**
     * @brief Deregisters a subscriber from a specific event.
     * @param eventID The event ID to unsubscribe from.
     * @param address Address or identifier of the subscriber.
     * @return True if deregistration is successful.
     */
    bool DeregisterSubscriber(uint32_t eventID, const std::string& address);

    /**
     * @brief Publishes an event to all registered subscribers.
     * @param eventID The event ID to publish.
     * @param payload Event data.
     */
    void PublishEvent(uint32_t eventID, const std::string& payload);

private:
    std::unordered_map<uint32_t, std::vector<Subscriber>> subscriptionMap_; ///< Event subscription mapping
    std::mutex mapMutex_; ///< Mutex for thread safety
    std::atomic<bool> running_; ///< Event Manager running state

    std::thread eventListenerThread_; ///< Event listener thread
    std::thread heartbeatThread_; ///< Heartbeat publisher thread

    void EventListener(); ///< Event listening loop
    void DispatchEvent(uint32_t eventID, const std::string& payload); ///< Dispatch event to subscribers
    void SendHeartbeat(); ///< Periodic heartbeat sender
};

#endif // EVENT_MANAGER_H
