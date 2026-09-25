#pragma once

#include "engine/math/vector4.h"

namespace Engine::Math {

    struct Rect {
        Vector2C m_min;
        Vector2C m_max;

        Rect() = default;
        Rect(Vector2C upper, Vector2C lower);

        bool intersects(const Rect& other);
    };

}