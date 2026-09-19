#pragma once

#include "comps/Body.h"
#include "snake-systems/Direction.h"

namespace sg {

class Snake {
private:
    Body m_snakeBody;
    Movement m_snakeDirection;

public:
    Snake() = default;

    int size() const noexcept;

    const Cell& getCell(int index) const noexcept;

    void setup();

    void setDirection(char key);

    void move();

    void snakeGrow();

    void printdd();
};

}