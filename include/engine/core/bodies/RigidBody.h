#pragma once

#include "engine/core/bodies/Cell.h"
#include "engine/math/Rect.h"
#include <array>
#include <vector>

namespace Engine::Core {

    template<std::size_t row, std::size_t col>
    class RigidBody {
    private:
        std::array<Cell, row * col> m_segments;
        bool m_active = false;
        Math::Vector2C m_origin {-1, -1};
        Math::Rect m_globalBounds;

    private:
        void setSprites(const std::vector<char>& sprites);

    public:
        RigidBody() = default;
        RigidBody(bool isActive);

        const std::array<Cell, row * col>& getSegments() const noexcept;

        Engine::Math::Rect getGlobalBounds() const noexcept;

        void setPosition(int x, int y) noexcept;

    };

}
