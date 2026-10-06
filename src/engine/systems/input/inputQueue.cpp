#include "engine/systems/input/inputQueue.h"

namespace Engine::io {

    io_Queue::io_Queue(std::size_t size)
        : m_keyboardBuffer(0, 0, size) {}

}