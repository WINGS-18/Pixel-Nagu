/**
 * This class work is to render the graphics or frame on the screen.
 * The class provides necessary overloaded draw functions to draw both RigidBody and
 * SoftBody.
 * Window is a template class, mainly templated to take inputs for height and width
 * of the game frame array.
 * This game frame array is a 1d array which is flattened to store 2d data.
 * Once drawing everything onto a grid we make a string buffer and push all characters into it or overwrite it.
 * At the end m_buffer is displayed. It boosts the performance and also avoids flickering.
 */

#pragma once

#include <iostream>
#include <array>
#include <string>

namespace Engine::Core {
    class RigidBody;
    class SoftBody;
}

namespace Engine::Render {
        
    template<std::size_t height, std::size_t width>
    class Window {
    private:
        std::array<char, height * width> m_frame;
        std::string m_buffer;

    public:
        Window();

        void frameReset();
        
        void draw(const Core::SoftBody& cell);

        void draw(const Core::RigidBody& cell);

        void makeBuffer();
        
        void display() noexcept;
    };

}

//template classes or template functions definations can be written
//in .tpp or .inl files, to avoid definations inside the .h file.
#include "engine/render/Window.tpp"