#pragma once

#include "Event.h"
#include "KBMCodes.h"

namespace Lofty
{
    /* * * *
     * KEYBOARD EVENTS
     */

    class KeyEvent : public Event
    {
    public:
        KeyEvent(Key key) : m_Key(key) {}
        virtual ~KeyEvent() = default;

        Key GetKey() { return m_Key; }

    protected:
        Key m_Key;
    };

    class KeyPressEvent : public KeyEvent
    {
        EVENT_INIT_TYPE("KeyPressEvent")
    public:
        KeyPressEvent(Key key, bool isRepeat) : KeyEvent(key), m_IsRepeat(isRepeat) {}
        virtual ~KeyPressEvent() = default;

        // we need to know sometimes if it is a repeat
        // as there is a delay between first press and repeat
        bool IsRepeat() { return m_IsRepeat; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressEvent: " << static_cast<int>(m_Key) << " Repeat: " << m_IsRepeat;
            return ss.str();
        }
    private:
        bool m_IsRepeat;
    };

    class KeyReleaseEvent : public KeyEvent
    {
        EVENT_INIT_TYPE("KeyReleaseEvent")
    public:
        KeyReleaseEvent(Key key) : KeyEvent(key) {}
        virtual ~KeyReleaseEvent() = default;

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleaseEvent: " << static_cast<int>(m_Key);
            return ss.str();
        }
    };


    /* * * *
     * MOUSE EVENTS
     */

    class MouseButtonEvent : public Event
    {
    public:
        MouseButtonEvent(MouseButton button): m_Button(button) {}
        virtual ~MouseButtonEvent() = default;

        MouseButton GetButton() { return m_Button; }

    protected:
        MouseButton m_Button;
    };

    class MousePressEvent : public MouseButtonEvent
    {
        EVENT_INIT_TYPE("MousePressEvent")
    public:
        MousePressEvent(MouseButton button) : MouseButtonEvent(button) {}
        virtual ~MousePressEvent() = default;

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MousePressEvent: " << static_cast<int>(m_Button);
            return ss.str();
        }
    };

    class MouseReleaseEvent : public MouseButtonEvent
    {
        EVENT_INIT_TYPE("MouseReleaseEvent")
    public:
        MouseReleaseEvent(MouseButton button) : MouseButtonEvent(button) {}
        virtual ~MouseReleaseEvent() = default;

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseReleaseEvent: " << static_cast<int>(m_Button);
            return ss.str();
        }
    };

    class MouseMoveEvent : public Event
    {
        EVENT_INIT_TYPE("MouseMoveEvent")
    public:
        MouseMoveEvent(double xpos, double ypos): m_xPos(xpos), m_yPos(ypos) {}
        virtual ~MouseMoveEvent() = default;

        double GetXPos() { return m_xPos; }
        double GetYPos() { return m_yPos; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMoveEvent: X-Pos=" << m_xPos << ", Y-Pos=" << m_yPos;
            return ss.str();
        }

    private:
        double m_xPos, m_yPos;
    };

    class ScrollEvent : public Event
    {
        EVENT_INIT_TYPE("ScrollEvent")
    public:
        ScrollEvent(double xoffset, double yoffset): m_xOffset(xoffset), m_yOffset(yoffset) {}
        virtual ~ScrollEvent() = default;

        double GetXOffset() { return m_xOffset; }
        double GetYOffset() { return m_yOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "ScrollEvent: X-Offset=" << m_xOffset << ", Y-Offset=" << m_yOffset;
            return ss.str();
        }

    private:
        double m_xOffset, m_yOffset;
    };

}