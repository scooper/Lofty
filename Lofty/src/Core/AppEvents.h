#pragma once

#include "Event.h"

namespace Lofty
{
    // 
    class AppResizeEvent : public Event
    {
        EVENT_INIT_TYPE("AppResizeEvent")
    public:
        AppResizeEvent(unsigned int width, unsigned int height): m_Width(width), m_Height(height) {};
        virtual ~AppResizeEvent() = default;

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "AppResizeEvent: W=" << m_Width << ", H=" << m_Height;
            return ss.str();
        }

    private:
        unsigned int m_Width, m_Height;
    };

    // 
    class AppCloseEvent : public Event
    {
        EVENT_INIT_TYPE("AppCloseEvent")
    public:
        AppCloseEvent() {};
        virtual ~AppCloseEvent() = default;

        std::string ToString() const override
        {
            return "AppCloseEvent";
        }
    };

    class AppMinimiseEvent : public Event
    {
        EVENT_INIT_TYPE("AppMinimiseEvent")
    public:
        AppMinimiseEvent() {};
        virtual ~AppMinimiseEvent() = default;

        std::string ToString() const override
        {
            return "AppMinimiseEvent";
        }
    };

    class AppRestoreEvent : public Event
    {
        EVENT_INIT_TYPE("AppRestoreEvent")
    public:
        AppRestoreEvent() {};
        virtual ~AppRestoreEvent() = default;

        std::string ToString() const override
        {
            return "AppRestoreEvent";
        }
    };
}