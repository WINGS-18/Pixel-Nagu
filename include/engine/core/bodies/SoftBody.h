/**
 * @file SoftBody.h
 * RigidBody class consists of a vector that stores multiple cells together.
 * The class can be used to replicate bending bodies.
 * It uses head and tail pointers to effectly move the body.
 */

#pragma once

#include "engine/core/bodies/Cell.h"
#include "engine/structures/RingBuffer.h"
#include "engine/math/direction-system/Direction.h"

namespace Engine::Core {

    class SoftBody {
    private:
        Flat::RingBuffer<Cell> m_segments;
        Flat::RingBuffer<Math::Vector2C> m_vertices;
        Engine::Movement m_direction;

    public:
        SoftBody(int head, int tail, std::size_t size);

        void initAllSprites(char sprite);

        Flat::RingBuffer<Cell>& getSegments() noexcept;
        const Flat::RingBuffer<Cell>& getSegments() const noexcept;

        void earlySetup();  //temp function

        void right();
        void left();
        void up();
        void down();

        void moveRight(std::size_t steps);
        void moveLeft(std::size_t steps);
        void moveUp(std::size_t steps);
        void moveDown(std::size_t steps);

        int head() const noexcept;
        int tail() const noexcept;

        void setCoordinates(int index, int x, int y);

    };

}