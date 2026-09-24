#pragma once

#include "engine/core/bodies/Cell.h"
#include <array>

namespace Engine::Core {

    template<std::size_t size>
    class SoftBody {
    private:
        std::array<Cell, size> m_segments;
        int m_head;
        int m_tail;

    public:
        SoftBody(int head, int tail);

        void initAllSprites(char sprite);

        const std::array<Cell, size>& getSegments() const noexcept;

        void earlySetup();  //temp function

        void expand();

        void right();
        void left();
        void up();
        void down();

        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();

        int getHead() const noexcept;
        int getTail() const noexcept;

        void setCoord(int index, int x, int y);

    };

}

#include "engine/core/bodies/SoftBody.tpp"