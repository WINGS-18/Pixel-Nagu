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

#include "ctl/flat_array.hpp"
#include "ctl/flat_string.hpp"

namespace Engine::Core {
    class RigidBody;
    class SoftBody;
}

namespace Engine::Render {
        
    class Window {
    private:
        ctl::flat_array<char> m_frame;
        ctl::flat_string m_buffer;

    public:
        Window(std::size_t height, std::size_t width);

        void frameReset();
        
        void draw(const Core::SoftBody& cell);
        void draw(const Core::RigidBody& cell);

        void writeLine(std::size_t horizontalPoint, std::size_t verticalPoint, const std::string& message);

        void makeBuffer();
        
        void display() noexcept;

    private:
        mutable bool m_open = false;
    
    public:
        bool isOpen() const noexcept;
        void close() const noexcept;
    };

}