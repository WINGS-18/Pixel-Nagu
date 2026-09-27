#pragma once

#include <cstddef>

namespace Engine::Math {

    struct Extents {
        int m_rows;
        int m_cols;

        Extents(int rows, int cols)
            : m_rows(rows), m_cols(cols) {}
    };
    

}