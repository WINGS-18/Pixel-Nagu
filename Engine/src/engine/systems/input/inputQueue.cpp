#include "engine/systems/input/inputQueue.h"
#include "engine/assets/Utilities.h"
#include <windows.h>

namespace Engine::Input {

    i_Queue::i_Queue(std::size_t size, const std::vector<int>& monitoredKeys, const std::vector<Action>& inorderToMonitoredKeys)
    : m_keyboardBuffer(size), m_monitoredKeys(monitoredKeys) {

        std::size_t count = std::min(m_monitoredKeys.size(), inorderToMonitoredKeys.size());

        for (std::size_t i = 0; i < count; i++) {
            int key = m_monitoredKeys[i];
            if (key >= 0 && static_cast<std::size_t>(key) < m_actionHash.size()) {
                m_actionHash[key] = inorderToMonitoredKeys[i];
            }
        }
    }

    Action i_Queue::translateKey(int key) noexcept {

        if(static_cast<unsigned int> (key) >= m_actionHash.size()) {
            return Action::NONE;
        }
        return m_actionHash[key];
    }

    void i_Queue::registerPress(std::uint64_t tick) noexcept {
        for(int key : m_monitoredKeys) {
            if(isKeyDown(key)) {
                m_keyboardBuffer.pushPrimitive(KeyAction{tick, translateKey(key)});
            }
        }
    }

    KeyAction i_Queue::getPressedKeyForPollKey() noexcept {
        if(m_keyboardBuffer.empty()) {
            return KeyAction{0, Action::NONE};
        }

        auto action = m_keyboardBuffer[m_keyboardBuffer.head()];
        m_keyboardBuffer.pop();
        return action;
    }

    Action i_Queue::getPressedKeyForWaitKey() noexcept {
        return translateKey(Utility::waitKey());
    }

    void i_Queue::clean_os_buffer() noexcept {
        while(Utility::pollKey() != '\0') {
            
        }
    }

    void i_Queue::cleanKeyboardBuffer() noexcept {
        m_keyboardBuffer.clear();
    }

    // void i_Queue::clearInputBuffers() noexcept {
    //     clean_os_buffer();
    //     cleanKeyboardBuffer();
    // }

    bool i_Queue::isKeyDown(int key) noexcept {
        return (GetAsyncKeyState(key) & 0x8000) != 0;
    }

}