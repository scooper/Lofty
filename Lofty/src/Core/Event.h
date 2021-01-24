#pragma once
#include <string>
#include <memory>
#include <functional>
#include <map>
#include <vector>

namespace Lofty
{

    struct EventType
    {
        const size_t id;
        const char* name;

        bool operator<(const EventType& other) const
        {
            return this->id < other.id;
        }

        bool operator==(const EventType& other) const
        {
            return this->id == other.id;
        }
    };


// I dont know if this is clever of stupid but basically a static variable is declared
// for a class, and the (static) memory address is used as an ID for the class type (so we have unique
// events, even if someone gives two events the same name)

// the idea is to call this at the start of every event class, passing a name into the macro
#define INIT_EVENT_TYPE(Name) \
public: \
    inline static const char* m_Name = Name; \
    inline static const EventType eventType = { reinterpret_cast<size_t>(&m_Name), Name }; \
    const EventType Type() const override { return eventType; }

    

    // event base
    class Event
    {
    public:
        // TODO: find out why it doesnt work without 'default' (and same with the events that inherit from it) - because I just changed stuff till it worked
        virtual ~Event() = default;
        virtual const EventType Type() const = 0;

        virtual std::string ToString() const { return Type().name; }
    };


    class EventDispatcher
    {
    public:
        inline static EventDispatcher& GetInstance()
        {
            static EventDispatcher instance;

            return instance;
        }

        void Subscribe(const EventType& type, std::function<void(const Event&)>&& function)
        {
            m_Observers[type].push_back(function);
        }

        void Post(const Event& event) const
        {
            EventType type = event.Type();

            if (m_Observers.find(type) == m_Observers.end())
                return;

            auto&& observersForType = m_Observers.at(type);

            for (auto&& observer : observersForType)
            {
                observer(event);
            }
        }

    public:
        EventDispatcher(EventDispatcher const&) = delete;
        void operator=(EventDispatcher const&) = delete;

    private:
        EventDispatcher() {}
        // the eventtype key might need rethinking here
        std::map <EventType, std::vector<std::function<void(const Event&)>>> m_Observers;

    };

    //// example event implementation
    //class DemoEvent : public Event
    //{
    //    INIT_EVENT_TYPE("DemoEvent")
    //public:
    //    DemoEvent();
    //    virtual ~DemoEvent();

    //    const EventType Type() const override
    //    {
    //        return eventType;
    //    }

    //    std::string ToString() const override
    //    {
    //        return eventType.name;
    //    }
    //};

}