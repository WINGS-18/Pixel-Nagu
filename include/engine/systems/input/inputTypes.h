#pragma once
#include <cstdint>

namespace Engine::Input {

    enum class Action : std::uint8_t{
        NONE,
        UP,
        DOWN,
        RIGHT,
        LEFT,
        EXIT
    };

}