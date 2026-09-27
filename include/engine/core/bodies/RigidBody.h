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
        
    private:
        void setSprites(const std::vector<char>& sprites);
        
    public:
        bool m_active = true;
        RigidBody() = default;
        RigidBody(bool isActive, int rows, int cols);

        const std::vector<Cell>& getSegments() const noexcept;

        Engine::Math::Rect getGlobalBounds() const noexcept;

        void setPosition(int x, int y) noexcept;

        bool isRigidBody() const noexcept;

    };

}