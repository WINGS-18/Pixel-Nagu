#pragma once

#include <array>

namespace Engine::Flat {

    template<typename T, std::size_t rows, std::size_t cols>
    class FlattArray {
    private:
        std::array<T, rows * cols> m_data;

    public:
        T& operator() (std::size_t x, std::size_t y);
        const T& operator() (std::size_t x, std::size_t y) const;

        void fullInit(const T& data);
    };

}

#include "engine/structures/Flatarray.tpp"