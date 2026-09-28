#include "engine/core/bodies/SoftBody.h"

namespace Engine::Core {

    SoftBody::SoftBody(int head, int tail)
        : m_head(head), m_tail(tail) {}

    SoftBody::SoftBody(int head, int tail, std::size_t size)
        : m_segments(size), m_head(head), m_tail(tail) {}


    void SoftBody::initAllSprites(char sprite) {
        for(auto& objs : m_segments) {
            objs.cellInit(sprite);
        }
    }

    const std::vector<Cell>& SoftBody::getSegments() const noexcept {
        return m_segments;
    }

    void SoftBody::earlySetup() {
        m_segments[0].m_transform.x = 3;
        m_segments[1].m_transform.x = 2;
        m_segments[2].m_transform.x = 1;
    }

    void SoftBody::right() {
        m_segments[m_head].m_transform.x++;
    }

    void SoftBody::left() {
        m_segments[m_head].m_transform.x--;
    }

    void SoftBody::up() {
        m_segments[m_head].m_transform.y--;
    }

    void SoftBody::down() {
        m_segments[m_head].m_transform.y++;
    }

    void SoftBody::expand() {
        int oldHead = m_head;
        m_head = (m_head + 1) % (m_segments.size());
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
    }

    void SoftBody::moveRight() {
        int oldHead = m_head;
        m_head = (m_head + 1) % (m_segments.size()); 
        
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
        right();
        
        m_tail = (m_tail + 1) % (m_segments.size());
    }

    void SoftBody::moveLeft() {
        int oldHead = m_head;
        m_head = (m_head + 1) % (m_segments.size()); 
        
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
        left();
        
        m_tail = (m_tail + 1) % (m_segments.size()); 
    }

    void SoftBody::moveUp() {
        int oldHead = m_head;
        m_head = (m_head + 1) % (m_segments.size()); 
        
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
        up();
        
        m_tail = (m_tail + 1) % (m_segments.size()); 
    }

    void SoftBody::moveDown() {
        int oldHead = m_head;
        m_head = (m_head + 1) % (m_segments.size()); 
        
        m_segments[m_head].m_transform = m_segments[oldHead].m_transform;
        down();
        
        m_tail = (m_tail + 1) % (m_segments.size()); 
    }

    int SoftBody::getHead() const noexcept{
        return m_head;
    }

    int SoftBody::getTail() const noexcept{
        return m_tail;
    }

    void SoftBody::setCoordinates(int index, int x, int y) {
        m_segments[index].m_transform.x = x;
        m_segments[index].m_transform.y = y;
    }
    
}