#include "engine/render/SpriteGrid.h"

namespace Engine::Render {

    //the args rows and cols multiply to give the size of the body
    SpriteGrid::SpriteGrid(std::size_t height, std::size_t width) 
        : m_segments(height, width) {}

    SpriteGrid::SpriteGrid(std::size_t height, std::size_t width, char cell) 
        : m_segments(height, width, cell) {}

    SpriteGrid::SpriteGrid(std::initializer_list<std::initializer_list<char>> sprite) 
        : m_segments(sprite) {}

    void SpriteGrid::setSprite(const ctl::flat_array<char>& sprite) {
        m_segments = sprite;
    }

    Math::vector2f SpriteGrid::origin() const noexcept {
        return m_origin;
    }
    
    Math::Rect<float> SpriteGrid::getGlobalBounds() const noexcept {
        return Math::Rect<float> {Math::vector2f{m_origin}, Math::vector2f{m_origin.x + (m_segments.columns() - 1), m_origin.y + (m_segments.rows() - 1)}};
    }

    const ctl::flat_array<char>& SpriteGrid::getSegments() const noexcept {
        return m_segments;
    }

    void SpriteGrid::setPosition(float x, float y) noexcept {
        m_origin.x = x;
        m_origin.y = y;
    }

    void SpriteGrid::move(Math::vector2f displacement) noexcept {
        m_origin += displacement;
    }
}