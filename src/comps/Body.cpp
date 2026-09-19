#include "comps/Body.h"
#include <iostream>

namespace sg {

    int Body::getSize() const noexcept {
        return m_size;
    }

    const std::array<Cell, 100>& Body::getBody() const noexcept {
        return m_body;
    }

    void Body::earlySetup() {
        m_body[0].m_coord.x = 2;
        m_body[1].m_coord.x = 1;
        m_body[2].m_coord.x = 0;
    }

    void Body::grow() {
        
    }

    void Body::right() {
        m_body[m_head].m_coord.x++;
    }

    void Body::left() {
        m_body[m_head].m_coord.x--;
    }

    void Body::up() {
        m_body[m_head].m_coord.y--;
    }

    void Body::down() {
        m_body[m_head].m_coord.y++;
    }

    void Body::moveRight() {
        m_body[m_tail].m_coord = m_body[m_head].m_coord;
        m_body[m_tail].m_coord.x++;
        headTailUpdate();
    }
    void Body::moveLeft() {
        m_body[m_tail].m_coord = m_body[m_head].m_coord;
        m_body[m_tail].m_coord.x--;
        headTailUpdate();
    }
    void Body::moveUp() {
        m_body[m_tail].m_coord = m_body[m_head].m_coord;
        m_body[m_tail].m_coord.y--;
        headTailUpdate();
    }
    void Body::moveDown() {
        m_body[m_tail].m_coord = m_body[m_head].m_coord;
        m_body[m_tail].m_coord.y++;
        headTailUpdate();
    }

    void Body::headTailUpdate() noexcept {
        if(m_tail == 0) {
            m_tail = m_size - 1;
        }else {
            m_tail--;
        }

        if(m_head == 0) {
            m_head = m_size - 1;
        }else {
            m_head--;
        }
    }

    void Body::printCoords(){
        for(int i = 0; i < m_size; i++) {
            std::cout << "(" << m_body[i].getX() << ", " << m_body[i].getY() << ")\t";
        }
        std::cout << "\n";
    }

}