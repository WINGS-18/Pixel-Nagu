#pragma once

#include "engine/math/Rect.h"
#include "engine/render/SpriteGrid.h"

namespace sg {

    class Wall {
    private:
        Engine::Render::SpriteGrid m_wallBody;

    public:
        Wall(std::size_t height, std::size_t width, char sprite);

        void setPosition(float x, float y);

        const Engine::Render::SpriteGrid& getSpriteGrid() const noexcept;

        Engine::Math::vector2f origin() const noexcept;

    };

}