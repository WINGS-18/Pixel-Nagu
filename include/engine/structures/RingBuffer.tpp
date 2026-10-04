#include "engine/structures/RingBuffer.h"

namespace Engine::Flat {

    template<typename T>
    RingBuffer<T>::RingBuffer(int head, int tail, std::size_t size)
        : m_data(size), m_head(head), m_tail(tail) {}

    template<typename T>
    std::vector<T>& RingBuffer<T>::getData() noexcept {
        return m_data;
    }
    
    template<typename T>
    const std::vector<T>& RingBuffer<T>::getData() const noexcept {
        return m_data;
    }

    template<typename T>
    int RingBuffer<T>::movePointers(int pointer, std::size_t size) noexcept {
        pointer = (pointer + size) % (m_data.size());   //increases the volume of the valid range (tail -> head).
        return pointer;
    }
    
    template<typename T>
    void RingBuffer<T>::reserveFront(std::size_t size) noexcept {
        m_head = movePointers(m_head, size);
    }

    template<typename T>
    void RingBuffer<T>::releaseBack(std::size_t size) noexcept {
        m_tail = movePointers(m_tail, size);
    }

    template<typename T>
    inline int RingBuffer<T>::head() const noexcept {
        return m_head;
    }

    template<typename T>
    inline int RingBuffer<T>::tail() const noexcept {
        return m_tail;
    }

    template<typename T>
    auto RingBuffer<T>::headIt() noexcept {
        return m_data.begin() + m_head % m_data.size();
    }

    template<typename T>
    auto RingBuffer<T>::tailIt() noexcept {
        return m_data.begin() + m_tail % m_data.size();
    }

    template<typename T>
    T& RingBuffer<T>::operator[] (std::size_t index) {
        return m_data[index % m_data.size()];
    }

    template<typename T>
    const T& RingBuffer<T>::operator[] (std::size_t index) const {
        return m_data[index % m_data.size()];
    }

}