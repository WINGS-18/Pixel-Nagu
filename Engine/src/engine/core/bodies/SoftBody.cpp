#include "engine/core/bodies/SoftBody.h"

namespace Engine::Core {

    SoftBody::SoftBody(std::size_t initSize, std::size_t reserveSize)
        : m_segments(initSize, reserveSize), m_vertices(initSize, reserveSize) {}

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
        m_segments[tail()].m_transform.x++;
    }

    void SoftBody::left() {
        m_segments[tail()].m_transform.x--;
    }

    void SoftBody::up() {
        m_segments[tail()].m_transform.y--;
    }

    void SoftBody::down() {
        m_segments[tail()].m_transform.y++;
    }

    void SoftBody::moveRight(std::size_t steps) {
        int oldHead = tail();
        m_segments.reserveBack(steps);

        m_segments[tail()].m_transform = m_segments[oldHead].m_transform;
        right();
        
        m_segments.releaseFront(steps);
    }

    void SoftBody::moveLeft(std::size_t steps) {
        int oldHead = tail();
        m_segments.reserveBack(steps);
        
        m_segments[tail()].m_transform = m_segments[oldHead].m_transform;
        left();
        
        m_segments.releaseFront(steps);
    }

    void SoftBody::moveUp(std::size_t steps) {
        int oldHead = tail();
        m_segments.reserveBack(steps);
        
        m_segments[tail()].m_transform = m_segments[oldHead].m_transform;
        up();
        
        m_segments.releaseFront(steps);
    }

    void SoftBody::moveDown(std::size_t steps) {
        int oldHead = tail();
        m_segments.reserveBack(steps);
        
        m_segments[tail()].m_transform = m_segments[oldHead].m_transform;
        down();
        
        m_segments.releaseFront(steps);
    }

    int SoftBody::head() const noexcept{
        return m_segments.head();
    }

    int SoftBody::tail() const noexcept{
        return m_segments.tail();
    }

    std::size_t SoftBody::size() const noexcept{
        return m_segments.size();
    }

    void SoftBody::setCoordinates(int index, int x, int y) {
        m_segments[index].m_transform.x = x;
        m_segments[index].m_transform.y = y;
    }
    
}