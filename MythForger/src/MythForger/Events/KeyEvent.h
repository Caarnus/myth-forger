#pragma once

#include <MythForger/Events/Event.h>
#include <MythForger/Core/KeyCodes.h>

namespace MythForger {

    class KeyEvent : public Event {
    public:
        KeyCode GetKeyCode() const { return m_KeyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
    protected:
        KeyEvent(const KeyCode keycode) : m_KeyCode(keycode) {
        }

        KeyCode m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent {
    public:
        KeyPressedEvent(const KeyCode keycode, bool isRepeat = false) : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

        int IsRepeat() const { return m_IsRepeat; }

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)
    protected:
        bool m_IsRepeat;
    };

    class KeyReleasedEvent : public KeyEvent {
    public:
        KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}