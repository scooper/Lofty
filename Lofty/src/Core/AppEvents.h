#pragma once

#include "Event.h"

namespace Lofty
{
    // 
    class AppResizeEvent : public Event
    {
        INIT_EVENT_TYPE("AppResizeEvent")
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
        INIT_EVENT_TYPE("AppCloseEvent")
    public:
        AppCloseEvent() {};
        virtual ~AppCloseEvent() = default;

        std::string ToString() const override
        {
            return "AppCloseEvent";
        }
    };
}