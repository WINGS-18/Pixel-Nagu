#pragma once

#include "engine/core/Cell.h"
#include <array>

namespace sg {

template<typename T, std::size_t size>
class Body {
private:
    std::array<T, size> m_body;
    int m_head;
    int m_tail;

public:
    Body(int head, int tail);

    void init(char sym);

    const std::array<T, size>& getBody() const noexcept;

    void earlySetup();  //temp function

    void grow();

    void right();
    void left();
    void up();
    void down();

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    void printCoords();

    int getHead() const noexcept;
    int getTail() const noexcept;

    void setCoord(int index, int x, int y);

};

}

#include "engine/core/Body.tpp"