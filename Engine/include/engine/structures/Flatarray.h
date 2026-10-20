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
        
        T& operator() (std::size_t x, std::size_t y);
        const T& operator() (std::size_t x, std::size_t y) const;

        void fullInit(const T& data);
    };

}


#include "engine/structures/Flatarray.tpp"