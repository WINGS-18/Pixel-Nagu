/**
 * @file Direction.h
 * It provides movement direction states.
 * All these states are wrapped under an enum class.
 */

#pragma once

namespace Engine {

    enum class Direction {
        up, down, right, left
    };

    class Movement {
    public:
        Direction m_currDir = Direction::right;
        Movement() = default;

        void setTheDirection(char key);

        bool opposite(const Direction& dir);
    };

}