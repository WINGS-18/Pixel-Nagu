#include "engine/structures/Flatarray.h"
#include <iostream>

namespace Engine::Flat {

    template<typename T>
    FlattArray<T>::FlattArray(std::size_t rows, std::size_t cols)
        : m_data(rows * cols), m_rowsncols(rows, cols) {}

    template<typename T>
    inline T& FlattArray<T>::operator() (std::size_t x, std::size_t y) {
        return m_data[(y * m_rowsncols.m_cols) + x];
    }

    template<typename T>
    inline const T& FlattArray<T>::operator() (std::size_t x, std::size_t y) const{
        return m_data[(y * m_rowsncols.m_cols) + x];
    }

    template<typename T>
    void FlattArray<T>::fullInit(const T& data) {
        std::fill(m_data.begin(), m_data.end(), data);
    }

}