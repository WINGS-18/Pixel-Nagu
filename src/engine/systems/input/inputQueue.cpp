#include "engine/systems/input/inputQueue.h"
#include "engine/assets/Utilities.h"

namespace Engine::io {

    io_Queue::io_Queue(std::size_t size)
        : m_keyboardBuffer(size) {}

    void io_Queue::registerPress() noexcept {

        char key = Utility::pollKey();

        if(key == '\0') {
            return;
        }


        if(m_keyboardBuffer.empty()) {
            m_keyboardBuffer.pushPrimitive(key);
            return;
        }

        if(!noise(key, m_keyboardBuffer[m_keyboardBuffer.tail()])) {
            m_keyboardBuffer.pushPrimitive(key);
        }
    
    }

    bool io_Queue::noise(char currKey, char prevKey) noexcept {
        return currKey == prevKey;
    }

    char io_Queue::getPressedKey() noexcept {
        if(m_keyboardBuffer.empty())    return '\0';

        auto ch = m_keyboardBuffer[m_keyboardBuffer.head()];
        m_keyboardBuffer.pop();
        return ch;
    }

    void io_Queue::clean_os_buffer() const noexcept {
        while(Utility::pollKey() != '\0') {
            
        }
    }

    void io_Queue::cleanKeyboardBuffer() noexcept {
        m_keyboardBuffer.clear();
    }

    void io_Queue::clearInputBuffers() noexcept {
        clean_os_buffer();
        cleanKeyboardBuffer();
    }

}