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
        Math::vector2f m_origin {0.0f, 0.0f};
        Math::Rect<float> m_globalBounds;
        
    public:
        bool m_active = true;

    public:
        RigidBody() = default;
        RigidBody(bool isActive, int rows, int cols);
        RigidBody(bool isActive, int rows, int cols, char sprite);
        void initAllSprites(char sym);
        
        const std::vector<Cell>& getSegments() const noexcept;
        
        Engine::Math::Rect<float> getGlobalBounds() const noexcept;    //returns a hitbox of the RigidBody
        
        void setPosition(float x, float y) noexcept;
        Math::vector2f origin() noexcept;
        void setSprites(const std::vector<char>& sprites);

    };

}