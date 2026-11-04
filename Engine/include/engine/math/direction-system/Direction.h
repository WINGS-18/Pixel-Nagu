/**
 * @file Direction.h
 * It provides movement direction states.
 * All these states are wrapped under an enum class.
 */

#pragma once

#include <cstdint>

namespace Engine::Input {
    struct KeyAction;
}

namespace Engine {

    enum class Direction : int {
        Right     = 0,
        DownRight = 45,
        Down      = 90,
        DownLeft  = 135,
        Left      = 180,
        UpLeft    = 225,
        Up        = 270,
        UpRight   = 315,
        Idle      = -1
    };

    class Movement {
    public:
        Direction m_currDir = Direction::Right;
        Movement() = default;

        void setTheDirection(Engine::Input::KeyAction action, std::uint64_t tick);

        bool opposite(const Direction& dir);
    };

}