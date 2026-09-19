#pragma once

#include "engine/math/vector2C.h"

namespace sg {

class Cell {
public:
    char m_symbol {'O'};
    Eng::Vector2C m_coord {0, 0};


    Cell() = default;

    int getX() const noexcept;

    int getY() const noexcept;

};

}