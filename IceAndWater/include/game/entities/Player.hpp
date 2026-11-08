#pragma once

#include "engine/core/bodies/RigidBody.h"
#include "engine/math/vector2C.h"
#include "game/entities/playerStates.hpp"
#include "engine/systems/input/inputQueue.h"
#include "engine/math/direction-system/Direction.h"

namespace icewater {

    class Player {
    private:
        Engine::Core::RigidBody m_body;
        Engine::Math::vector2f m_position = {0.0f, 28.0f};
        Engine::Math::vector2f m_velocity = {8.0f, 8.0f};
        Engine::Direction m_direction = Engine::Direction::UpRight;

        Roles m_role;
        States m_state;

    public:
        Engine::Input::i_Queue m_playerEvents;

    public:
        Player() = default;
        Player(int rows, int cols, char sprite, Roles role, States state);
        
        void launch(float launchSpeed);
        void updateVelocity(float dt);
        void move(float dt);

        const Engine::Core::RigidBody& getBody() const noexcept;
    };
}