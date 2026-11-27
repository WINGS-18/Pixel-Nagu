#pragma once

#include "ctl/ring_buffer.hpp"
#include "engine/math/vector2C.h"
#include "engine/render/SpriteGrid.h"
#include "engine/systems/input/inputQueue.h"

namespace sg {

    // enum class Direction : std::uint8_t {
    //     NONE,
    //     RIGHT,
    //     LEFT,
    //     UP,
    //     DOWN
    // };

    class Snake {
    private:
        ctl::ring_buffer<Engine::Math::vector2f> m_segments;
        int m_score = 0;
        Engine::Input::Action m_currDirection = Engine::Input::Action::RIGHT;
        char m_sprite {'O'};
        bool m_didGrow = false;

    public:
        Engine::Input::i_Queue m_snakeEvents;

    public:
        Snake(std::size_t capacity);

        void incrementScore() noexcept;
        int getScore() const noexcept;
        void resetScore() noexcept {m_score = 0;}

        void setDirection(Engine::Input::KeyAction action, std::uint64_t tick);
        bool opposite(Engine::Input::Action action);
        void setup();

        void moveSnake(Engine::Math::vector2f directionVector) noexcept;
        void move() noexcept;
        void clear() noexcept;

        const ctl::ring_buffer<Engine::Math::vector2f>& getSegments() const noexcept;
        const Engine::Math::vector2f& head() const noexcept;
        char sprite() const noexcept;

        bool didSelfCollide();
        void snakeAteFood();

    };



    class Food {
    private:
        Engine::Render::SpriteGrid m_food;

    public:
        Food(std::initializer_list<std::initializer_list<char>> sprite);

        bool wasEaten(Engine::Math::Rect<float> transform) noexcept;
        Engine::Math::Rect<float> getGlobalBounds() const noexcept;
        void setPosition(float x, float ys);

        const Engine::Render::SpriteGrid& getSpriteGrid() const noexcept;
    };

}
