#pragma once

#include <iostream>
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
        
    template<std::size_t height, std::size_t width>
    class Window {
    private:
        std::array<std::array<char, width>, height> m_frame;

    public:
        Window();

        void frameReset();
        
        template <isSoftBody T>
        void draw(const T& cell);

        template <isRigidBody T>
        void draw(const T& cell);
        
        void display() const noexcept;
    };

}
#include "engine/render/Window.tpp"