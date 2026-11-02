#pragma once

#include "engine/core/bodies/RigidBody.h"
#include "engine/math/vector2C.h"
#include "game/entities/playerStates.hpp"
#include "engine/systems/input/inputQueue.h"

namespace icewater {

    class Player {
    private:
        Engine::Core::RigidBody m_body;
        Engine::Math::vector2f m_position = {0.0f, 0.0f};
        Engine::Math::vector2f m_velocity = {2.0f, 2.0f};
        int angle = 45;

        Roles m_role;
        States m_state;

    public:
        Engine::Input::i_Queue m_playerEvents;

    public:
        Player() = default;
        Player(int rows, int cols, char sprite, Roles role, States state);
        
        void updateVelocity(float dt);
        void move(float dt);
    };
}