/**
 * @file RigidBody.h
 * RigidBody class consists of a vector that stores multiple cells together.
 * The class even holds 2d structures into a single contigous block(flattened 2d -> 1d).
 * This class provides a RigidBody.
 */

#pragma once

#include "engine/core/bodies/Cell.h"
#include "engine/math/Rect.h"
#include "engine/math/Extents.h"
#include <vector>

namespace Engine::Core {

    class RigidBody {
    private:
        std::vector<Cell> m_segments;
        Math::Extents m_rowsncols;
        Math::Vector2C m_origin {-1, -1};
        Math::Rect m_globalBounds;
        
    public:
        bool m_active = true;

    public:
        RigidBody() = default;
        RigidBody(bool isActive, int rows, int cols);
        void initAllSprites(char sym);
        
        const std::vector<Cell>& getSegments() const noexcept;
        
        Engine::Math::Rect getGlobalBounds() const noexcept;    //returns a hitbox of the RigidBody
        
        void setPosition(int x, int y) noexcept;
        void setSprites(const std::vector<char>& sprites);

    };

}