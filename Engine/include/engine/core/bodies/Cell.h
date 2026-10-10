/**
 * @file Cell.h
 * Cell class consists of a sprite which is used store appearence.
 * m_transform that holds x and y coordinates.
 * This class serves as a basic building block of anything in the game(atom level).
 */

#pragma once

#include "engine/math/vector2C.h"

namespace Engine::Core {

    struct Cell {
        char m_sprite {'O'};
        Engine::Math::Vector2C m_transform {1, 1};

        Cell() = default;

        void cellInit(char sprite);     //initialises the Cell's sprite
    };

}