#include "engine/render/Window.h"
#include "engine/core/bodies/SpriteGrid.h"
#include <iostream>

namespace Engine::Render {

    Window::Window(std::size_t height, std::size_t width)
        : m_frame(height, width), m_buffer(height, width, ' '), m_open(true) {
        frameReset();
    }

    void Window::draw(const Core::SpriteGrid& body) {
        if(body.m_active) {
            auto& entity = body.getSegments();
            
            std::size_t i = 0;
            for(const auto cell : entity) {
                std::size_t x_offset = i % body.getSegments().columns();
                std::size_t y_offset = i / body.getSegments().columns();

                m_frame(static_cast<int> (body.origin().y + y_offset), static_cast<int> (body.origin().x + x_offset)) = cell;

                i++;
            }
        }
    }

    void Window::writeLine(std::size_t horizontalPoint, std::size_t verticalPoint, const std::string& message) {
        for(const char& letter : message) {
            m_frame(verticalPoint, horizontalPoint++) = letter;
        }
    }

    void Window::frameReset() {
        m_frame.fill(' ');
    }

    void Window::makeBuffer() {
        for(std::size_t i = 0; i < m_frame.rows(); i++) {
            for(std::size_t j = 0; j < m_frame.columns(); j++) {
                //placing every sprite onto the buffer by skipping the "\n" slots.
                m_buffer(i, j) = m_frame(i, j);
            }
        }
    }

    void Window::display() noexcept {
        makeBuffer();
        std::cout << m_buffer.getData();
    }
    
    inline bool Window::isOpen() const noexcept {
        return m_open;
    }

    inline void Window::close() const noexcept {
        m_open = false;
    }

}