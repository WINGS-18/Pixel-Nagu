#pragma once

#include "engine/core/bodies/Cell.h"
#include <vector>

namespace Engine::Core {

    class SoftBody {
    private:
        std::vector<Cell> m_segments;
        int m_head;
        int m_tail;

    public:
        SoftBody(int head, int tail);
        SoftBody(int head, int tail, std::size_t size);

        void initAllSprites(char sprite);

        const std::vector<Cell>& getSegments() const noexcept;

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

        bool isSoftBody() const noexcept;

    };

}