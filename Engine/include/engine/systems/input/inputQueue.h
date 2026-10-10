#pragma once

#include "engine/structures/RingBuffer.h"
#include "engine/systems/input/inputTypes.h"
#include <array>

namespace Engine::Input {

    class i_Queue {
    private:
        Flat::RingBuffer<Action> m_keyboardBuffer;
        std::array<Action, 256> m_actionHash;

    public:
        i_Queue(std::size_t size);

        Action translateKey(char key) noexcept;
        
        void registerPress() noexcept;
        bool noise(Action currAction, Action prevAction) noexcept;

        Action getPressedKey() noexcept;

        void clean_os_buffer() const noexcept;
        void cleanKeyboardBuffer() noexcept;

        void clearInputBuffers() noexcept;
    };

}