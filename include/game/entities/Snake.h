#pragma once

#include "engine/core/bodies/SoftBody.h"
#include "engine/math/direction-system/Direction.h"

namespace sg {

    namespace ec = Engine::Core;

    class Snake {
    private:
        ec::SoftBody<100> m_snakeBody;
        Engine::Movement m_snakeDirection;

    public:
        Snake(int head, int tail);

        const ec::Cell& getCell(int index) const noexcept;

        const ec::SoftBody<100>& getBody() const noexcept;

        void setup();

        void setDirection(char key);

        void move();

        void snakeGrow();

        void printdd();

        int head() const noexcept;
        int tail() const noexcept;
        int fullSize() const noexcept;
    };

}