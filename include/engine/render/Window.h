/**
 * This class work is to render the graphics or frame on the screen.
 * The class provides necessary overloaded draw functions to draw both RigidBody and
 * SoftBody.
 * Window is a template class, mainly templated to take inputs for height and width
 * of the game frame array.
 */

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

//template classes or template functions definations can be written
//in .tpp or .inl files, to avoid definations inside the .h file.
#include "engine/render/Window.tpp"