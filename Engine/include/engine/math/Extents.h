/**
 * @file Extents.h
 * Extents struct provides rows and columns storage, both being packed into a single structure.
 */

#pragma once

#include <cstdint>

namespace Engine::Math {

    struct Extents {
        std::size_t m_rows;
        std::size_t m_cols;

        Extents(std::size_t rows, std::size_t cols)
            : m_rows(rows), m_cols(cols) {}
            
    };
    

}