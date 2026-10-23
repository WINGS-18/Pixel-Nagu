#pragma once

#include <vector>
#include "engine/math/Extents.h"

namespace Engine::Flat {

    template<typename T>
    class FlattArray {
    private:
        std::vector<T> m_data;
    
    public:
        Math::Extents m_rowsncols;

    public:
        FlattArray(std::size_t rows, std::size_t cols);
        FlattArray(std::size_t rows, std::size_t cols, const T& completeInitialize);
        
        T& operator() (std::size_t x, std::size_t y);
        const T& operator() (std::size_t x, std::size_t y) const;

        std::size_t rows() const noexcept;
        std::size_t columns() const noexcept;

        auto begin() noexcept;
        auto end() noexcept;
        
        auto begin() const noexcept;
        auto end() const noexcept;

        void fill(const T& data);

    public:
        FlattArray(const FlattArray&) = default;
        FlattArray& operator= (const FlattArray&) = default;
    
        FlattArray(FlattArray&&) = default;
        FlattArray& operator= (FlattArray&&) = default;
    
        ~FlattArray() = default;
    };

}


#include "engine/structures/Flatarray.tpp"