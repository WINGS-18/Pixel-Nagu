#include "engine/core/bodies/RigidBody.h"

namespace Engine::Core {

    template<std::size_t row, std::size_t col>
    RigidBody<row, col>::RigidBody(bool isActive) 
        : m_active(isActive) {}

    template<std::size_t row, std::size_t col>
    void RigidBody<row, col>::setSprites(const std::vector<char>& sprites) {
        int i = 0;
        for(const char sprite : sprites) {
            if(sprite != '`')
                m_segments[i++].m_sprite = sprite;
        }
    }
    
    template<std::size_t row, std::size_t col>
    Math::Rect RigidBody<row, col>::getGlobalBounds() const noexcept {
        auto b = m_segments.begin();
        auto e = m_segments.end();

        Math::Vector4 uVec = {Math::Vector2C(m_segments[0].m_transform), Math::Vector2C(m_segments[col - 1].m_transform)};
        Math::Vector4 lVec = {Math::Vector2C(m_segments[(row - 1) * col].m_transform), Math::Vector2C(m_segments[row * col - 1].m_transform)};

        return Math::Rect {uVec, lVec};
    }

    template<std::size_t row, std::size_t col>
    const std::array<Cell, row * col>& RigidBody<row, col>::getSegments() const noexcept {
        return m_segments;
    }

    template<std::size_t row, std::size_t col>
    void RigidBody<row, col>::setPosition(int x, int y) noexcept {
        m_origin.x = x;
        m_origin.y = y;

        int currentX = x;
        int currentY = y;
        int i = 0;

        for(auto& cell : m_segments) {
            if(i == col) {
                i = 0;                 
                currentX = m_origin.x; 
                currentY++;            
            }
            
            cell.m_transform.x = currentX++;
            cell.m_transform.y = currentY;

            i++; 
        }
    }

}