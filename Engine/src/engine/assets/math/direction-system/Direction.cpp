#include "engine/math/direction-system/Direction.h"
#include "engine/systems/input/inputTypes.h"

namespace Engine {

    namespace ip = Input;

    void Movement::setTheDirection(Input::Action action) {

        switch(action) {

            case ip::Action::LEFT :
                if(!opposite(Direction::left))
                    m_currDir = Direction::left;
                break;

            case ip::Action::RIGHT :
                if(!opposite(Direction::right))
                    m_currDir = Direction::right;
                break;

            case ip::Action::UP :
                if(!opposite(Direction::up))
                    m_currDir = Direction::up;
                break;

            case ip::Action::DOWN :
                if(!opposite(Direction::down))
                    m_currDir = Direction::down;
                break;
        }
    }

    bool Movement::opposite(const Direction& dir) {
        if(dir == Direction::right && m_currDir == Direction::left) return true;
        if(dir == Direction::left && m_currDir == Direction::right) return true;
        if(dir == Direction::up && m_currDir == Direction::down) return true;
        if(dir == Direction::down && m_currDir == Direction::up) return true;
        return false;
    }

}