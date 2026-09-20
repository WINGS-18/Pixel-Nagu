#pragma once

#include "game/entities/Snake.h"
#include "game/entities/Wall.h"

class GameRender {
private:
    std::array<std::array<char, 50>, 30> m_frame;

public:
    GameRender();

    void frameReset();

    template <typename T>
    void insertEntity(const T& cell);

    void display() const noexcept;
};

template <typename T>
void GameRender::insertEntity(const T& cell) {
    int i;
    for(i = cell.tail(); i < cell.head(); i++) {
        m_frame[cell.getCell(i).getY()][cell.getCell(i).getX()] = cell.getCell(i).m_symbol;
    }
}