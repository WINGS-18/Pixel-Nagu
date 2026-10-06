#include "engine/structures/RingBuffer.h"

namespace Engine::Flat {

    template<typename T>
    RingBuffer<T>::RingBuffer(std::size_t initSize, std::size_t reserveSize)
        : m_data(reserveSize), m_head(0), m_tail(static_cast<int> (initSize)), m_size(initSize) {}

    template<typename T>
    std::vector<T>& RingBuffer<T>::getData() noexcept {
        return m_data;
    }
    
    template<typename T>
    const std::vector<T>& RingBuffer<T>::getData() const noexcept {
        return m_data;
    }

    template<typename T>
    std::size_t RingBuffer<T>::size() const noexcept {
        return m_size;
    }

    template<typename T>
    int RingBuffer<T>::movePointers(int pointer, std::size_t size) noexcept {
        pointer = (pointer + size) % (m_data.size());   //increases the volume of the valid range (tail -> head).
        return pointer;
    }
    
    template<typename T>
    void RingBuffer<T>::releaseFront(std::size_t size) noexcept {
        m_head = movePointers(m_head, size);
    }

    template<typename T>
    void RingBuffer<T>::releaseBack(std::size_t size) noexcept {
        m_tail--;
    }

    template<typename T>
    void RingBuffer<T>::reserveBack(std::size_t size) noexcept {
        m_tail = movePointers(m_tail, size);
    }

    template<typename T>
    void RingBuffer<T>::push(const T& data) noexcept {
        m_data[m_tail] = data;
        reserveBack(1);
    }

    template<typename T>
    void RingBuffer<T>::push(T&& data) noexcept {
        m_data[m_tail] = std::move(data);
        reserveBack(1);
    }

    template<typename T>
    void RingBuffer<T>::pop() noexcept {
        
    }

    template<typename T>
    void RingBuffer<T>::clear() noexcept {
        m_head = 0;
        m_tail = 0;
    }

    template<typename T>
    inline int RingBuffer<T>::head() const noexcept {
        return m_head;
    }

    template<typename T>
    inline int RingBuffer<T>::tail() const noexcept {
        return m_tail - 1;
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