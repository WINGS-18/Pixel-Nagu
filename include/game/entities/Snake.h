#pragma once

#include "engine/core/Body.h"
#include "engine/math/direction-system/Direction.h"

namespace sg {

class Snake {
private:
    Body<Cell, 100> m_snakeBody;
    Movement m_snakeDirection;

public:
    Snake(int head, int tail);

    const Cell& getCell(int index) const noexcept;

    void setup();

    void setDirection(char key);

    void move();

    void snakeGrow();

    void printdd();

    int head() const noexcept;
    int tail() const noexcept;
};

}