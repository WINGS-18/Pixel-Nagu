#pragma once

namespace sg {

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