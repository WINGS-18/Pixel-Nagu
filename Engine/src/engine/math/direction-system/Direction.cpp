#include "engine/math/direction-system/Direction.h"
#include "engine/systems/input/inputTypes.h"
#include "engine/systems/input/inputQueue.h"

namespace Engine {

    namespace ip = Input;

    void Movement::setTheDirection(ip::KeyAction action, std::uint64_t tick) {

        auto tickDifference = tick - action.m_tick;
        if(tickDifference >= 3) return;

        switch(action.m_action) {

            case ip::Action::LEFT :
                if(!opposite(Direction::Left))
                    m_currDir = Direction::Left;
                break;

            case ip::Action::RIGHT :
                if(!opposite(Direction::Right))
                    m_currDir = Direction::Right;
                break;

            case ip::Action::UP :
                if(!opposite(Direction::Up))
                    m_currDir = Direction::Up;
                break;

            case ip::Action::DOWN :
                if(!opposite(Direction::Down))
                    m_currDir = Direction::Down;
                break;

            case ip::Action::NONE :

            case ip::Action::EXIT :
                break;
                
            default :
                break;
        }
    }

    bool Movement::opposite(const Direction& dir) {
        if(dir == Direction::Right && m_currDir == Direction::Left) return true;
        if(dir == Direction::Left && m_currDir == Direction::Right) return true;
        if(dir == Direction::Up && m_currDir == Direction::Down) return true;
        if(dir == Direction::Down && m_currDir == Direction::Up) return true;
        return false;
    }

}