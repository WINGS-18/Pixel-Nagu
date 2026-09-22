#pragma once

#include "engine/math/vector2C.h"

namespace Engine::Core {

    struct Cell {
        char m_sprite {'O'};
        Engine::Math::Vector2C m_transform {1, 1};

        Cell() = default;

        void cellInit(char sprite);
    };

}