#pragma once

#include "comps/Cell.h"
#include <array>

namespace sg {

class Body {
private:

void headTailUpdate() noexcept;

public:
std::array<Cell, 100> m_body;
    int m_head = 0;
    int m_tail = 2;
    int m_size = 3;
    Body() = default;

    int getSize() const noexcept;

    const std::array<Cell, 100>& getBody() const noexcept;

    void earlySetup();  //temp function

    void grow();

    void right();
    void left();
    void up();
    void down();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    void printCoords();

};

}