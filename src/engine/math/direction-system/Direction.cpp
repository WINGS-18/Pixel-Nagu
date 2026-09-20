#include "engine/math/direction-system/Direction.h"

namespace sg {

    void Movement::setTheDirection(char key) {

        switch(key) {

            case 'a' :
                if(!opposite(Direction::left))
                    m_currDir = Direction::left;
                break;

            case 'd' :
                if(!opposite(Direction::right))
                    m_currDir = Direction::right;
                break;

            case 'w' :
                if(!opposite(Direction::up))
                    m_currDir = Direction::up;
                break;

            case 's' :
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