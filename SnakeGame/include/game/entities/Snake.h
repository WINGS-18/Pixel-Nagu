#pragma once

#include "engine/core/bodies/SoftBody.h"
#include "engine/core/bodies/RigidBody.h"
#include "engine/math/direction-system/Direction.h"

namespace sg {

    namespace ec = Engine::Core;

    class Snake {
    private:
        ec::SoftBody m_snakeBody;
        Engine::Movement m_snakeDirection;
        int m_score = 0;

    public:
        Snake(std::size_t initSize, std::size_t reserveSize);

        const ec::Cell& getCell(int index) const noexcept;
        ec::Cell& getCell(int index) noexcept;

        void incrementScore() noexcept;
        int getScore() const noexcept;

        const ec::SoftBody& getBody() const noexcept;

        void setup();

        void setDirection(Engine::Input::Action action);

        void move();

        bool didSelfCollide();

        void expand();
        void snakeGrow();

        void printdd();

        int head() const noexcept;
        int tail() const noexcept;
        int fullSize() const noexcept;
    };



    class Food {
    private:
        ec::RigidBody m_food;

    public:
        Food(char sprite);

        ec::RigidBody& getBody() noexcept;
        const ec::RigidBody& getBody() const noexcept;

        bool wasEaten(Engine::Math::Rect transform) noexcept;
        Engine::Math::Rect getGlobalBounds() const noexcept;
        void setPosition(int x, int ys);
    };

}