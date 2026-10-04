/**
 * RingBuffer class provides various methods to use array like a queue.
 * Provides excellent cache locality and even the classis templated meaning can be used for any data type storage.
 */

#pragma once

#include <vector>

namespace Engine::Flat {

    template<typename T>
    class RingBuffer {
    private:
        std::vector<T> m_data;
        int m_head, m_tail;

    public:
        RingBuffer(int head, int tail, std::size_t size);

        int movePointers(int pointer, std::size_t size) noexcept;
        void reserveFront(std::size_t size) noexcept;
        void releaseBack(std::size_t size) noexcept;

        int head() const noexcept;
        int tail() const noexcept;

        //returns iterators at head and tail.
        auto headIt() noexcept;
        auto tailIt() noexcept;

        std::vector<T>& getData() noexcept;
        const std::vector<T>& getData() const noexcept;

        T& operator[] (std::size_t index);
        const T& operator[] (std::size_t index) const;
    };

}

#include "engine/structures/RingBuffer.tpp"