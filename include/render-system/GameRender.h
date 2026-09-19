#pragma once

#include "../entities/Snake.h"

class GameRender {
private:
    std::array<std::array<char, 50>, 30> m_frame;

public:
    GameRender();

    void frameReset();

    // template <typename T>
    void insertEntity(const sg::Snake& cell);

    void display() const noexcept;
};

// template <typename T>
