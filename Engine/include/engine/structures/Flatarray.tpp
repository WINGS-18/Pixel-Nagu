#include "engine/structures/Flatarray.h"
#include <iostream>

namespace Engine::Flat {

    template<typename T, std::size_t rows, std::size_t cols>
    inline T& FlattArray<T, rows, cols>::operator() (std::size_t x, std::size_t y) {
        return m_data[(y * cols) + x];
    }

    template<typename T, std::size_t rows, std::size_t cols>
    inline const T& FlattArray<T, rows, cols>::operator() (std::size_t x, std::size_t y) const{
        return m_data[(y * cols) + x];
    }

    template<typename T, std::size_t rows, std::size_t cols>
    void FlattArray<T, rows, cols>::fullInit(const T& data) {
        m_data.fill(data);
    }

}