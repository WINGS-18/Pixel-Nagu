#include "engine/core/bodies/SoftBody.h"

namespace Engine::Core {

    template <std::size_t size>
    SoftBody<size>::SoftBody(int head, int tail)
        : m_head(head), m_tail(tail) {}


    template<std::size_t size>
    void SoftBody<size>::initAllSprites(char sprite) {
        for(auto& objs : m_segments) {
            objs.cellInit(sprite);
        }
    }

    template<std::size_t size>
    const std::array<Cell, size>& SoftBody<size>::getSegments() const noexcept {
        return m_segments;
    }

    template<std::size_t size>
    void SoftBody<size>::earlySetup() {
        m_segments[0].m_transform.x = 3;
        m_segments[1].m_transform.x = 2;
        m_segments[2].m_transform.x = 1;
    }

    template<std::size_t size>
    void SoftBody<size>::right() {
        m_segments[m_head].m_transform.x++;
    }

    template<std::size_t size>
    void SoftBody<size>::left() {
        m_segments[m_head].m_transform.x--;
    }

    template<std::size_t size>
    void SoftBody<size>::up() {
        m_segments[m_head].m_transform.y--;
    }

    template<std::size_t size>
    void SoftBody<size>::down() {
        m_segments[m_head].m_transform.y++;
    }

    template<std::size_t size>
    void SoftBody<size>::expand() {
        int oldHead = m_head;
        m_head = (m_head + 1) % size;
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
    }

    template<std::size_t size>
    void SoftBody<size>::moveRight() {
        int oldHead = m_head;
        m_head = (m_head + 1) % size; 
        
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
        right();
        
        m_tail = (m_tail + 1) % size;
    }

    template<std::size_t size>
    void SoftBody<size>::moveLeft() {
        int oldHead = m_head;
        m_head = (m_head + 1) % size; 
        
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
        left();
        
        m_tail = (m_tail + 1) % size; 
    }

    template<std::size_t size>
    void SoftBody<size>::moveUp() {
        int oldHead = m_head;
        m_head = (m_head + 1) % size; 
        
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
        up();
        
        m_tail = (m_tail + 1) % size; 
    }

    template<std::size_t size>
    void SoftBody<size>::moveDown() {
        int oldHead = m_head;
        m_head = (m_head + 1) % size; 
        
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
        down();
        
        m_tail = (m_tail + 1) % size; 
    }

    template<std::size_t size>
    int SoftBody<size>::getHead() const noexcept{
        return m_head;
    }

    template<std::size_t size>
    int SoftBody<size>::getTail() const noexcept{
        return m_tail;
    }

    template<std::size_t size>
    bool SoftBody<size>::isSoftBody() const noexcept {return true;}

    template<std::size_t size>
    void SoftBody<size>::setCoord(int index, int x, int y) {
        m_segments[index].m_transform.x = x;
        m_segments[index].m_transform.y = y;
    }
    
}