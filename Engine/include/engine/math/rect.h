/**
 * @file rect.h
 * Rect stands for Rectangle.
 * Provides hitbox.
 * Holds m_min(top left corner) && m_max(bottom right).
 * This rectangular area is hitbox for an entity.
 */

#pragma once

#include "engine/math/vector2C.h"

namespace Engine::Math {

    struct Rect {
        Vector2C m_min;
        Vector2C m_max;

        Rect() = default;
        Rect(Vector2C upper, Vector2C lower);

        bool intersect(const Rect& other);
    };

}