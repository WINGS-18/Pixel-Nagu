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

    template<IsAllowed T>
    struct Rect {
        Vector2C<T> m_min;
        Vector2C<T> m_max;

        Rect() = default;
        Rect(Vector2C<T> upper, Vector2C<T> lower);

        bool intersect(const Rect<T>& other);
    };

}

#include "engine/math/rect.tpp"