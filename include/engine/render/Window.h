#pragma once

#include <array>

namespace Engine::Render {

    template<typename T>
    concept isSoftBody = requires(T obj) {
        obj.isSoftBody();
    };

    template<typename T>
    concept isRigidBody = requires(T obj) {
        obj.isRigidBody();
    };
        
    class Window {
    private:
        std::array<std::array<char, 50>, 30> m_frame;

    public:
        Window();

        void frameReset();

        template <isSoftBody T>
        void draw(const T& cell);

        template <isRigidBody T>
        void draw(const T& cell);
        
        void display() const noexcept;
    };
    
    template <isSoftBody T>
    void Window::draw(const T& cell) {
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

    template <isRigidBody T>
    void Window::draw(const T& cell) {
        if(cell.m_active) {
            for(const auto& unit : cell.getSegments()) {
                m_frame[unit.m_transform.y][unit.m_transform.x] = unit.m_sprite;
            }
        }
    }

}