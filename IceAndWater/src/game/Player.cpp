#include "entities/Player.hpp"

namespace icewater {

    Player::Player(int rows, int cols, char sprite, Roles role, States state)
        : m_body(true, 2, 2, sprite), m_role(role), m_state(state) {}

    void Player::move(float dt) {
        m_body.move(m_velocity * dt);
    }

}