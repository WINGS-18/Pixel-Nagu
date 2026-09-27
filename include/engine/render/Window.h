#pragma once

#include <iostream>
#include <array>

namespace Engine::Core {
    class RigidBody;
    class SoftBody;
}

namespace Engine::Render {
    
    template<std::size_t height, std::size_t width>
    class Window {
    private:
        std::array<std::array<char, width>, height> m_frame;

    public:
        Window();

        void frameReset();
        
        void draw(const Core::SoftBody& cell);

        void draw(const Core::RigidBody& cell);
        
        void display() const noexcept;
    };

}
#include "engine/render/Window.tpp"