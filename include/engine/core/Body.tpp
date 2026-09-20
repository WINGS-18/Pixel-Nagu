#include "engine/core/Body.h"
#include <iostream>

namespace Engine::Core {

    template <typename T, std::size_t size>
    Body<T, size>::Body(int head, int tail)
        : m_head(head), m_tail(tail) {} 

    template <typename T, std::size_t size>
    void Body<T, size>::init(char sym) {
        for(auto& objs : m_body) {
            objs.m_symbol = sym;
        }
    }

    template <typename T, std::size_t size>
    const std::array<T, size>& Body<T, size>::getBody() const noexcept {
        return m_body;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::earlySetup() {
        m_body[0].m_coord.x = 3;
        m_body[1].m_coord.x = 2;
        m_body[2].m_coord.x = 1;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::grow() {
        int oldHead = m_head++;
        m_body[m_head].m_coord = m_body[oldHead].m_coord;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::right() {
        m_body[m_head].m_coord.x++;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::left() {
        m_body[m_head].m_coord.x--;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::up() {
        m_body[m_head].m_coord.y--;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::down() {
        m_body[m_head].m_coord.y++;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::moveRight() {
        int oldHead = m_head++;
        m_body[m_head].m_coord = m_body[oldHead].m_coord;
        right();
        m_tail++;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::moveLeft() {
        int oldHead = m_head++;
        m_body[m_head].m_coord = m_body[oldHead].m_coord;
        left();
        m_tail++;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::moveUp() {
        int oldHead = m_head++;
        m_body[m_head].m_coord = m_body[oldHead].m_coord;
        up();
        m_tail++;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::moveDown() {
        int oldHead = m_head++;
        m_body[m_head].m_coord = m_body[oldHead].m_coord;
        down();
        m_tail++;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::printCoords(){
        for(int i = m_tail; i < m_head; i++) {
            std::cout << "(" << m_body[i].getX() << ", " << m_body[i].getY() << ")\t";
        }
        std::cout << "\n";
    }

    template <typename T, std::size_t size>
    int Body<T, size>::getHead() const noexcept{
        return m_head;
    }

    template <typename T, std::size_t size>
    int Body<T, size>::getTail() const noexcept{
        return m_tail;
    }

    template <typename T, std::size_t size>
    void Body<T, size>::setCoord(int index, int x, int y) {
        m_body[index].setX(x);
        m_body[index].setY(y);
    }
    
}