#include "engine/render/Window.h"
#include "engine/core/bodies/RigidBody.h"
#include "engine/core/bodies/SoftBody.h"

namespace Engine::Render {

    template<std::size_t height, std::size_t width>
    void Window<height, width>::draw(const Core::SoftBody& cell) {
        if(cell.getTail() < cell.getHead()) {
            for(int i = cell.getTail(); i <= cell.getHead(); i++) {
                m_frame[(cell.getSegments()[i].m_transform.y * width) + cell.getSegments()[i].m_transform.x] = cell.getSegments()[i].m_sprite;
            }
        } else {
            for(int i = 0; i <= cell.getHead(); i++) {
                m_frame[(cell.getSegments()[i].m_transform.y * width) + cell.getSegments()[i].m_transform.x] = cell.getSegments()[i].m_sprite;
            }
            
            for(int i = cell.getTail(); i < cell.getSegments().size(); i++) {
                m_frame[(cell.getSegments()[i].m_transform.y * width) + cell.getSegments()[i].m_transform.x] = cell.getSegments()[i].m_sprite;
            }
        }
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::draw(const Core::RigidBody& cell) {
        if(cell.m_active) {
            for(const auto& unit : cell.getSegments()) {
                m_frame[(unit.m_transform.y * width) + unit.m_transform.x] = unit.m_sprite;
            }
        }
    }

    template<std::size_t height, std::size_t width>
    Window<height, width>::Window() {
        frameReset();
        //reserving capacity of height * width which tells us how many
        //characters are there in the grid, and + height is extra space
        //for adding null character.
        m_buffer.assign(height * width + height, ' ');

        //loops through the buffer and inserts "\n" at exact end of the width sizes
        //it is indication that row ends.
        for(std::size_t i = 0; i < height; i++) {
            m_buffer[(i * (width + 1)) + width] = '\n';
        }
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::frameReset() {
        m_frame.fill(' ');
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::makeBuffer() {
        for(std::size_t i = 0; i < height; i++) {
            for(std::size_t j = 0; j < width; j++) {
                //placing every sprite onto the buffer by skipping the "\n" slots.
                m_buffer[(i * (width + 1)) + j] = m_frame[(i * width) + j];
            }
        }
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::display() noexcept {
        makeBuffer();
        std::cout << m_buffer;
    }


}