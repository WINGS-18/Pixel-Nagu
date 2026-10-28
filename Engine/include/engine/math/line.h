/**
 * This Line class holds two end points of a line.
 * Uses Vector2C from @file vector2c to keep hold on two of the end points.
 */

#pragma once

#include "engine/math/vector2C.h"

namespace Engine::Math {

    template<IsAllowed T>
    struct Line {
        Vector2C<T> m_vecLeft {0, 0};
        Vector2C<T> m_vecRight {0, 0};

        Line() = default;

        Line(Vector2C<T> vecl, Vector2C<T> vecr)
            : m_vecLeft(vecl), m_vecRight(vecr) {}

    };

    using Line2f = Line<float>;
    using Line2i = Line<int>;
    
}