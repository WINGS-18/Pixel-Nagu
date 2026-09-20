#pragma once

#include <array>

namespace Engine::Render {
        
    class Window {
    private:
        std::array<std::array<char, 50>, 30> m_frame;

    public:
        Window();

        void frameReset();

        template <typename T>
        void draw(const T& cell);

        void display() const noexcept;
    };

    template <typename T>
    void Window::draw(const T& cell) {
        int i;
        for(i = cell.tail(); i < cell.head(); i++) {
            m_frame[cell.getCell(i).getY()][cell.getCell(i).getX()] = cell.getCell(i).m_symbol;
        }
    }

}