#include "engine/render/Window.h"
#include "engine/core/bodies/RigidBody.h"
#include "engine/core/bodies/SoftBody.h"
#include <iostream>
#include <utility>

namespace Engine::Render {

    Window::Window(std::size_t height, std::size_t width)
        : m_frame(height, width), m_buffer(height, width, ' '), m_open(true) {
        frameReset();
    }

    void Window::draw(const Core::SoftBody& body) {
        const auto& renderable = body.getSegments();
        const auto size = renderable.size();

        for(std::size_t i = 0; i < size; i++) {
            m_frame(renderable[i].m_transform.x, renderable[i].m_transform.y) = renderable[i].m_sprite;
        }

    }

    void Window::draw(const Core::RigidBody& body) {
        if(body.m_active) {
            for(const auto& cell : body.getSegments()) {
                m_frame(cell.m_transform.x, cell.m_transform.y) = cell.m_sprite;
            }
        }
    }

    void Window::frameReset() {
        m_frame.fullInit(' ');
    }

    void Window::makeBuffer() {
        for(std::size_t i = 0; i < m_frame.m_rowsncols.m_rows; i++) {
            for(std::size_t j = 0; j < m_frame.m_rowsncols.m_cols; j++) {
                //placing every sprite onto the buffer by skipping the "\n" slots.
                m_buffer(j, i) = m_frame(j, i);
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