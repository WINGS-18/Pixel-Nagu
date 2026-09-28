/**
 * This Line class holds two end points of a line.
 * Uses Vector2C from @file vector2c to keep hold on two of the end points.
 */

#pragma once

#include "engine/math/vector2C.h"

namespace Engine::Math {

    struct Line {
        Vector2C m_vecLeft {0, 0};
        Vector2C m_vecRight {0, 0};

        Line() = default;

        Line(Vector2C vec1, Vector2C vec2);

    };
    
}