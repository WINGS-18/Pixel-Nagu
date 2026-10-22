#include "engine/structures/Flatarray.h"

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
    inline std::size_t FlattArray<T>::rows() const noexcept {
        return m_rowsncols.m_rows;
    }

    template<typename T>
    inline auto FlattArray<T>::begin() noexcept {
        return m_data.begin();
    }

    template<typename T>
    inline auto FlattArray<T>::end() noexcept {
        return m_data.end();
    }

    template<typename T>
    inline auto FlattArray<T>::begin() const noexcept {
        return m_data.cbegin();
    }

    template<typename T>
    inline auto FlattArray<T>::end() const noexcept {
        return m_data.cend();
    }

    template<typename T>
    inline std::size_t FlattArray<T>::columns() const noexcept {
        return m_rowsncols.m_cols;
    }

    template<typename T>
    void FlattArray<T>::fill(const T& data) {
        std::fill(begin(), end(), data);
    }

}