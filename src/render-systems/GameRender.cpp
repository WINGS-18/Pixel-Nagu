#include "render-system/GameRender.h"
#include <iostream>

GameRender::GameRender() {
    frameReset();
}

void GameRender::frameReset() {
    for (auto& row : m_frame) {
        row.fill(' '); 
    }
}

void GameRender::display() const noexcept {
    for(auto& row : m_frame) {
        for(auto& cell : row) {
            std::cout << cell;
        }

        std::cout << "\n";
    }
}

void GameRender::insertEntity(const sg::Snake& cell) {
    for(int i = 0; i < cell.size(); i++) {
        m_frame[cell.getCell(i).getY()][cell.getCell(i).getX()] = cell.getCell(i).m_symbol;
    }
}