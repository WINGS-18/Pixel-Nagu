/**
 * @file Extents.h
 * Extents struct provides rows and columns storage, both being packed into a single structure.
 */

#pragma once

namespace Engine::Math {

    struct Extents {
        int m_rows;
        int m_cols;

        Extents(int rows, int cols)
            : m_rows(rows), m_cols(cols) {}
    };
    

}