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
        if(cell.tail() < cell.head()) {
            for(int i = cell.tail(); i <= cell.head(); i++) {
                m_frame[cell.getCell(i).getY()][cell.getCell(i).getX()] = cell.getCell(i).m_symbol;
            }
        }else {
            for(int i = 0; i <= cell.head(); i++) {
                m_frame[cell.getCell(i).getY()][cell.getCell(i).getX()] = cell.getCell(i).m_symbol;
            }
            
            for(int i = cell.tail(); i < cell.fullSize(); i++) {
                m_frame[cell.getCell(i).getY()][cell.getCell(i).getX()] = cell.getCell(i).m_symbol;
            }
        }
    }

}