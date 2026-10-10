/**
 * Use case of this is only for render buffer for now atleast.
 */

#pragma once

#include <string>
#include "engine/math/Extents.h"

namespace Engine::Flat {

    class FlattString {
    private:
        std::string m_data;
        Math::Extents m_rowsncols;

    public:
        FlattString(std::size_t rows, std::size_t cols, char defaultValue);
        
        const std::string& getData() const noexcept;
        
    private:
        void setEndCharacters();

    public:
        inline char& operator() (int x, int y) {
            return m_data[(y * (m_rowsncols.m_cols + 1)) + x];
        }
    };
    
}