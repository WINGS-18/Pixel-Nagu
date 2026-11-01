#include "engine/core/bodies/RigidBody.h"

namespace Engine::Core {

    //the args rows and cols multiply to give the size of the body
    RigidBody::RigidBody(bool isActive, int rows, int cols) 
        : m_segments(rows * cols), m_rowsncols(rows, cols), m_active(isActive) {}

    RigidBody::RigidBody(bool isActive, int rows, int cols, char sprite) 
        : m_segments(rows * cols), m_rowsncols(rows, cols), m_active(isActive) {
            initAllSprites(sprite);
    }

    void RigidBody::setSprites(const std::vector<char>& sprites) {  //end your rows using ' ` '
        int i = 0;
        for(const char sprite : sprites) {
            // ` -> character tells that it is the end of that row
            if(sprite != '`')
                m_segments[i++].m_sprite = sprite;
        }
    }

    void RigidBody::initAllSprites(char sym) {
        for(auto& cell : m_segments) {
            cell.cellInit(sym);
        }
    }

    Math::vector2f RigidBody::origin() const noexcept {
        return m_origin;
    }

    Math::Extents RigidBody::getRowsnCols() const noexcept {
        return m_rowsncols;
    }
    
    Math::Rect<float> RigidBody::getGlobalBounds() const noexcept {
        return Math::Rect<float> {Math::vector2f{m_origin}, Math::vector2f{m_origin.x + (m_rowsncols.m_cols - 1), m_origin.y + (m_rowsncols.m_rows - 1)}};
    }

    const std::vector<Cell>& RigidBody::getSegments() const noexcept {
        return m_segments;
    }

    void RigidBody::setPosition(float x, float y) noexcept {
        m_origin.x = x;
        m_origin.y = y;
    }

    void RigidBody::move(Math::vector2f displacement) noexcept {
        m_origin = displacement;
    }
}