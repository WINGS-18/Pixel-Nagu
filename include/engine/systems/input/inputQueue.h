#pragma once

#include "engine/structures/RingBuffer.h"

namespace Engine::io {

    class io_Queue {
    private:
        Flat::RingBuffer<char> m_keyboardBuffer;

    public:
        io_Queue(std::size_t size);
        
        void registerPress() noexcept;
        bool noise(char currKey, char prevKey) noexcept;

        char getPressedKey() noexcept;

        void clean_os_buffer() const noexcept;
        void cleanKeyboardBuffer() noexcept;

        void clearInputBuffers() noexcept;
    };

}