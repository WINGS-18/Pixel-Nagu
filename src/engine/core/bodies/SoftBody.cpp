#include "engine/core/bodies/SoftBody.h"

namespace Engine::Core {

    SoftBody::SoftBody(int head, int tail, std::size_t size)
        : m_segments(head, tail, size), m_vertices(0, 0, size) {}

    void SoftBody::initAllSprites(char sprite) {
        for(auto& objs : m_segments.getData()) {
            objs.cellInit(sprite);
        }
    }

    Flat::RingBuffer<Cell>& SoftBody::getSegments() noexcept {
        return m_segments;
    }

    const Flat::RingBuffer<Cell>& SoftBody::getSegments() const noexcept {
        return m_segments;
    }

    void SoftBody::earlySetup() {
        m_segments[0].m_transform.x = 3;
    }

    void SoftBody::right() {
        m_segments[head()].m_transform.x++;
    }

    void SoftBody::left() {
        m_segments[head()].m_transform.x--;
    }

    void SoftBody::up() {
        m_segments[head()].m_transform.y--;
    }

    void SoftBody::down() {
        m_segments[head()].m_transform.y++;
    }

    void SoftBody::moveRight(std::size_t steps) {
        int oldHead = head();
        m_segments.reserveFront(steps);

        m_segments[head()].m_transform = m_segments[oldHead].m_transform;
        right();
        
        m_segments.releaseBack(steps);
    }

    void SoftBody::moveLeft(std::size_t steps) {
        int oldHead = head();
        m_segments.reserveFront(steps);
        
        m_segments[head()].m_transform = m_segments[oldHead].m_transform;
        left();
        
        m_segments.releaseBack(steps);
    }

    void SoftBody::moveUp(std::size_t steps) {
        int oldHead = head();
        m_segments.reserveFront(steps);
        
        m_segments[head()].m_transform = m_segments[oldHead].m_transform;
        up();
        
        m_segments.releaseBack(steps);
    }

    void SoftBody::moveDown(std::size_t steps) {
        int oldHead = head();
        m_segments.reserveFront(steps);
        
        m_segments[head()].m_transform = m_segments[oldHead].m_transform;
        down();
        
        m_segments.releaseBack(steps);
    }

    int SoftBody::head() const noexcept{
        return m_segments.head();
    }

    int SoftBody::tail() const noexcept{
        return m_segments.tail();
    }

    void SoftBody::setCoordinates(int index, int x, int y) {
        m_segments[index].m_transform.x = x;
        m_segments[index].m_transform.y = y;
    }
    
}