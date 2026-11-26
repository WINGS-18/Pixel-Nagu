/**
 * @file RigidBody.h
 * RigidBody class consists of a vector that stores multiple cells together.
 * The class even holds 2d structures into a single contigous block(flattened 2d -> 1d).
 * This class provides a RigidBody.
 */

#pragma once

#include "engine/math/Rect.h"
#include "ctl/flat_array.hpp"

namespace Engine::Render {

    class SpriteGrid {
    private:
        ctl::flat_array<char> m_segments;
        Math::vector2f m_origin {0.0f, 0.0f};

    public:
        bool m_active = true;

    public:
        SpriteGrid(std::size_t height, std::size_t width);
        SpriteGrid(std::size_t height, std::size_t width, char cell);
        SpriteGrid(std::initializer_list<std::initializer_list<char>> sprite);

        void setSprite(const ctl::flat_array<char>& sprite);
        
        const ctl::flat_array<char>& getSegments() const noexcept;
        
        void setPosition(float x, float y) noexcept;
        void move(Math::vector2f displacement) noexcept;
        
        Math::vector2f origin() const noexcept;
        Engine::Math::Rect<float> getGlobalBounds() const noexcept;    //returns a hitbox of the RigidBody

    };

}