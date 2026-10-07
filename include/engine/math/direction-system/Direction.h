/**
 * @file Direction.h
 * It provides movement direction states.
 * All these states are wrapped under an enum class.
 */

#pragma once

#include <cstdint>

namespace Engine::Input {
    enum class Action : std::uint8_t;
}

namespace Engine {

    enum class Direction {
        up, down, right, left
    };

    class Movement {
    public:
        Direction m_currDir = Direction::right;
        Movement() = default;

        void setTheDirection(Engine::Input::Action action);

        bool opposite(const Direction& dir);
    };

}