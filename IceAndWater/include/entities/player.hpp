#pragma once

#include "engine/core/bodies/RigidBody.h"
#include "engine/math/vector2C.h"
#include "entities/playerStates.hpp"

namespace icewater {

    class Player {
    private:
        Engine::Core::RigidBody m_body;
        Engine::Math::vector2f m_position = {0.0f, 0.0f};
        Engine::Math::vector2f m_velocity = {0.0f, 0.0f};

        Roles m_role;
        States m_state;

    public:
        Player(Roles role, States state);
        
        void updateVelocity(float dt);
        void updatePosition(float dt);
    };
}