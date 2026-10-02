#include "engine/core/bodies/RigidBody.h"

namespace Engine::Core {

    //the args rows and cols multiply to give the size of the body
    RigidBody::RigidBody(bool isActive, int rows, int cols) 
        : m_segments(rows * cols), m_rowsncols(rows, cols), m_active(isActive) {}

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

    Math::Vector2C RigidBody::origin() noexcept {
        return m_origin;
    }
    
    Math::Rect RigidBody::getGlobalBounds() const noexcept {
        return Math::Rect {Math::Vector2C{m_segments[0].m_transform}, Math::Vector2C{m_segments[m_rowsncols.m_rows * m_rowsncols.m_cols - 1].m_transform}};
    }

    const std::vector<Cell>& RigidBody::getSegments() const noexcept {
        return m_segments;
    }

    void RigidBody::setPosition(int x, int y) noexcept {

        //here origin means the top left corner of the entity
        m_origin.x = x;
        m_origin.y = y;

        int currentX = x;
        int currentY = y;
        int i = 0;

        for(auto& cell : m_segments) {
            if(i == m_rowsncols.m_cols) {
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