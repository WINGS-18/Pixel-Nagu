#include "engine/render/Window.h"
#include "engine/core/bodies/RigidBody.h"
#include "engine/core/bodies/SoftBody.h"

namespace Engine::Render {

    template<std::size_t height, std::size_t width>
    void Window<height, width>::draw(const Core::SoftBody& body) {
        if(body.getTail() < body.getHead()) {
            for(int i = body.getTail(); i <= body.getHead(); i++) {
                const auto& cell = body.getSegments()[i];
                m_frame(cell.m_transform.x, cell.m_transform.y)= cell.m_sprite;
            }
        } else {
            for(int i = 0; i <= body.getHead(); i++) {
                const auto& cell = body.getSegments()[i];
                m_frame(cell.m_transform.x, cell.m_transform.y) = cell.m_sprite;
            }
            
            for(int i = body.getTail(); i < body.getSegments().size(); i++) {
                const auto& cell = body.getSegments()[i];
                m_frame(cell.m_transform.x, cell.m_transform.y) = cell.m_sprite;
            }
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
    Window<height, width>::Window() : m_buffer(height, width, ' ') {
        frameReset();
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


}