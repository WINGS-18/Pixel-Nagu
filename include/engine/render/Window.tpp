#include "engine/render/Window.h"

namespace Engine::Render {

    template<std::size_t height, std::size_t width>
    template <isSoftBody T>
    void Window<height, width>::draw(const T& cell) {
        if(cell.getTail() < cell.getHead()) {
            for(int i = cell.getTail(); i <= cell.getHead(); i++) {
                m_frame[cell.getSegments()[i].m_transform.y][cell.getSegments()[i].m_transform.x] = cell.getSegments()[i].m_sprite;
            }
        } else {
            for(int i = 0; i <= cell.getHead(); i++) {
                m_frame[cell.getSegments()[i].m_transform.y][cell.getSegments()[i].m_transform.x] = cell.getSegments()[i].m_sprite;
            }
            
            for(int i = cell.getTail(); i < cell.getSegments().size(); i++) {
                m_frame[cell.getSegments()[i].m_transform.y][cell.getSegments()[i].m_transform.x] = cell.getSegments()[i].m_sprite;
            }
        }
    }

    template<std::size_t height, std::size_t width>
    template <isRigidBody T>
    void Window<height, width>::draw(const T& cell) {
        if(cell.m_active) {
            for(const auto& unit : cell.getSegments()) {
                m_frame[unit.m_transform.y][unit.m_transform.x] = unit.m_sprite;
            }
        }
    }

    template<std::size_t height, std::size_t width>
    Window<height, width>::Window() {
        frameReset();
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::frameReset() {
        for (auto& row : m_frame) {
            row.fill(' '); 
        }
    }

    template<std::size_t height, std::size_t width>
    void Window<height, width>::display() const noexcept {
        for(auto& row : m_frame) {
            for(auto& cell : row) {
                std::cout << cell;
            }
            std::cout << "\n";
        }
    }


}