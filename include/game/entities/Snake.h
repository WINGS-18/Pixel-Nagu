#pragma once

#include "engine/core/Body.h"
#include "engine/math/direction-system/Direction.h"

namespace sg {

    namespace ec = Engine::Core;

    class Snake {
    private:
        ec::Body<ec::Cell, 100> m_snakeBody;
        Engine::Movement m_snakeDirection;

    public:
        Snake(int head, int tail);

        const ec::Cell& getCell(int index) const noexcept;

        void setup();

        void setDirection(char key);

        void move();

        void snakeGrow();

        void printdd();

        int head() const noexcept;
        int tail() const noexcept;
    };

}