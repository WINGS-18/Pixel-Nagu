#pragma once

#include "engine/math/vector2C.h"

namespace sg {

struct Cell {
    char m_symbol {'O'};
    Eng::Vector2C m_coord {1, 1};

    Cell() = default;
    Cell(char sym);

    int getX() const noexcept;
    int getY() const noexcept;

    void setX(int x) noexcept;
    void setY(int y) noexcept;

};

}