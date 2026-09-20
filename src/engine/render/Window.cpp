#include "engine/render/Window.h"
#include <iostream>

namespace Engine::Render {

    Window::Window() {
        frameReset();
    }

    void Window::frameReset() {
        for (auto& row : m_frame) {
            row.fill(' '); 
        }
    }

    void Window::display() const noexcept {
        for(auto& row : m_frame) {
            for(auto& cell : row) {
                std::cout << cell;
            }
            std::cout << "\n";
        }
    }

}