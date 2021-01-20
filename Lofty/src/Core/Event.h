#pragma once
#include <string>

struct EventType
{
    const unsigned int id;
    const std::string name;
};

// event base
class Event
{
public:
    virtual ~Event();
    virtual const EventType Type() const = 0;

    virtual std::string ToString() const { return Type().name; }
};


class EventDispatcher
{
public:
    EventDispatcher();

private:
};

class EventTypeHandler
{
public:
    static unsigned int GetEventId() { return m_IdCount++; };

private:
    static unsigned int m_IdCount;
};

// example event implementation
//class DemoEvent : public Event
//{
//public:
//    const EventType Type() const override
//    {
//        return { EventTypeHandler::GetEventId(), "DemoEvent"};
//    }
//
//    std::string ToString() const override
//    {
//        return "";
//    }
//};