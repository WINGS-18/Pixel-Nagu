#pragma once

#include "engine/core/Body.h"

namespace sg {

    namespace ec = Engine::Core;

    class Wall {
    private:
        ec::Body<ec::Cell, 160> m_wallBody;

    public:
        Wall(int head, int tail);

        void init(char sym);

        void setTheWall();

        void setRight(int& i, int xLimit, int yLimit);
        void setLeft(int& i, int xLimit, int yLimit);
        void setTop(int& i, int xLimit, int yLimit);
        void setDown(int& i, int xLimit, int yLimit);

        const ec::Cell& getCell(int index) const noexcept;

        int head() const noexcept;
        int tail() const noexcept;
        int fullSize() const noexcept;
    };

}