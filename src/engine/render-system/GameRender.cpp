#include "engine/render-system/GameRender.h"
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