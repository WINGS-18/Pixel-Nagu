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

#include "engine/structures/Flatarray.h"
#include "engine/structures/Flatstring.h"

namespace Engine::Core {
    class RigidBody;
    class SoftBody;
}

namespace Engine::Render {
        
    template<std::size_t height, std::size_t width>
    class Window {
    private:
        Flat::FlattArray<char, height, width> m_frame;
        Flat::FlattString m_buffer;

    public:
        Window();

        void frameReset();
        
        void draw(const Core::SoftBody& cell);

        void draw(const Core::RigidBody& cell);

        void makeBuffer();
        
        void display() noexcept;

    private:
        mutable bool m_open = false;
    
    public:
        bool isOpen() const noexcept;
        void close() const noexcept;
    };

}

//template classes or template functions definations can be written
//in .tpp or .inl files, to avoid definations inside the .h file.
#include "engine/render/Window.tpp"