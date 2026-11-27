#include "game/entities/Wall.h"
#include "engine/math/vector2C.h"
#include "engine/render/SpriteGrid.h"

namespace sg {

    Wall::Wall(std::size_t height, std::size_t width, char sprite)
        : m_wallBody(height, width, sprite) {}

    const Engine::Render::SpriteGrid& Wall::getSpriteGrid() const noexcept {
        return m_wallBody;
    }

    void Wall::setPosition(float x, float y) {
        m_wallBody.setPosition(x, y);
    }

    Engine::Math::vector2f Wall::origin() const noexcept {
        return m_wallBody.origin();
    }

}