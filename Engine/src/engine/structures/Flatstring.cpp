#include "engine/structures/Flatstring.h"

namespace Engine::Flat {

    FlattString::FlattString(std::size_t rows, std::size_t cols, char defaultValue) : m_rowsncols(rows, cols) {
        m_data.assign((rows * cols) + rows, defaultValue);
        setEndCharacters();
    }

    const std::string& FlattString::getData() const noexcept {
        return m_data;
    }

    void FlattString::setEndCharacters() {
        //loops through the buffer and inserts "\n" at exact end of the width sizes
        //it is indication that row ends.
        for(std::size_t i = 0; i < m_rowsncols.m_rows; i++) {
            m_data[(i * (m_rowsncols.m_cols + 1)) + m_rowsncols.m_cols] = '\n';
        }
    }
    
}