#pragma once

#include "engine/structures/RingBuffer.h"

namespace Engine::io {

    class io_Queue {
    private:
        Flat::RingBuffer<char> m_keyboardBuffer;

    public:
        io_Queue(std::size_t size);
        
    };

}