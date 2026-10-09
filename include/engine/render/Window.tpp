#include "engine/render/Window.h"
#include "engine/core/bodies/RigidBody.h"
#include "engine/core/bodies/SoftBody.h"
#include <iostream>
#include <utility>

namespace Engine::Render {

    template<std::size_t height, std::size_t width>
    Window<height, width>::Window()
        : m_buffer(height, width, ' '), m_open(true) {
        frameReset();
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::draw(const Core::SoftBody& body) {
        const auto& renderable = body.getSegments();
        const auto size = renderable.size();

        for(auto i = 0; i < size; i++) {
            m_frame(renderable[i].m_transform.x, renderable[i].m_transform.y) = renderable[i].m_sprite;
        }
 
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::draw(const Core::RigidBody& body) {
        if(body.m_active) {
            for(const auto& cell : body.getSegments()) {
                m_frame(cell.m_transform.x, cell.m_transform.y) = cell.m_sprite;
            }
        }
    }


    template<std::size_t height, std::size_t width>
    void Window<height, width>::frameReset() {
        m_frame.fullInit(' ');
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::makeBuffer() {
        for(std::size_t i = 0; i < height; i++) {
            for(std::size_t j = 0; j < width; j++) {
                //placing every sprite onto the buffer by skipping the "\n" slots.
                m_buffer(j, i) = m_frame(j, i);
            }
        }
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::display() noexcept {
        makeBuffer();
        std::cout << m_buffer.getData();
    }
    
    template<std::size_t height, std::size_t width>
    inline bool Window<height, width>::isOpen() const noexcept {
        return m_open;
    }

    template<std::size_t height, std::size_t width>
    inline void Window<height, width>::close() const noexcept {
        m_open = false;
    }

}