#include "engine/systems/input/inputQueue.h"
#include "engine/assets/Utilities.h"

namespace Engine::Input {

    i_Queue::i_Queue(std::size_t size)
        : m_keyboardBuffer(size) {

        m_actionHash.fill(Action::NONE);

        m_actionHash['w'] = Action::UP;
        m_actionHash['a'] = Action::LEFT;
        m_actionHash['s'] = Action::DOWN;
        m_actionHash['d'] = Action::RIGHT;
        m_actionHash['q'] = Action::EXIT;
    }

    Action i_Queue::translateKey(char key) noexcept {
        auto unsignedKey = static_cast<unsigned char> (key);
        return m_actionHash[unsignedKey];
    }

    void i_Queue::registerPress() noexcept {

        while(m_keyboardBuffer.size() != m_keyboardBuffer.getData().capacity()) {
        char key = Utility::pollKey();

        if(key == '\0') {
            return;
        }

        auto translatedKey = translateKey(key);

        if(m_keyboardBuffer.empty()) {
            m_keyboardBuffer.pushPrimitive(translatedKey);
            return;
        }

        auto noise = [&] () {return translatedKey == m_keyboardBuffer[m_keyboardBuffer.tail()];};

        if(!noise()) {
            m_keyboardBuffer.pushPrimitive(translatedKey);
        }
    }
    
    }

    bool i_Queue::noise(Action currAction, Action prevAction) noexcept {
        return currAction == prevAction;
    }

    Action i_Queue::getPressedKey() noexcept {
        if(m_keyboardBuffer.empty()) {
            return Action::NONE;
        }

        auto ch = m_keyboardBuffer[m_keyboardBuffer.head()];
        m_keyboardBuffer.pop();
        return ch;
    }

    void i_Queue::clean_os_buffer() const noexcept {
        while(Utility::pollKey() != '\0') {
            
        }
    }

    void i_Queue::cleanKeyboardBuffer() noexcept {
        m_keyboardBuffer.clear();
    }

    void i_Queue::clearInputBuffers() noexcept {
        clean_os_buffer();
        cleanKeyboardBuffer();
    }

}