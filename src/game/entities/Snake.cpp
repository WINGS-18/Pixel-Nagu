#include "game/entities/Snake.h"
#include <iostream>

namespace sg {

    namespace ec = Engine::Core;
    namespace en = Engine;
    namespace ei = en::Input;

    Snake::Snake(std::size_t initSize, std::size_t reserveSize)
        : m_snakeBody(initSize, reserveSize) {}

    const ec::Cell& Snake::getCell(int index) const noexcept {
        return m_snakeBody.getSegments()[index];
    }

    const ec::SoftBody& Snake::getBody() const noexcept {
        return m_snakeBody;
    }

    void Snake::setup() {
        m_snakeBody.earlySetup();
    }

    void Snake::setDirection(ei::Action action) {
        m_snakeDirection.setTheDirection(action);
    }

    bool Snake::didSelfCollide() {
        auto& body = m_snakeBody.getSegments();
        if(body.size() <= 4) {
            return false;
        }

        for(auto i = 0; i < body.size() - 1; i++) {
            if(body[i].m_transform == body[head()].m_transform) {
                return true;
            }
        }

        return false;
    }

    void Snake::move() {
        
        switch(m_snakeDirection.m_currDir) {
            
            case en::Direction::right :
                m_snakeBody.moveRight(1);
            break;
            
            case en::Direction::left :
                m_snakeBody.moveLeft(1);
                break;

            case en::Direction::up :
                m_snakeBody.moveUp(1);
                break;

            case en::Direction::down :
                m_snakeBody.moveDown(1);
                break;
        }
    }

    void Snake::expand() {
        int oldHead = head();
        m_snakeBody.getSegments().reserveBack(1);
        m_snakeBody.getSegments()[head()].m_transform = m_snakeBody.getSegments()[oldHead].m_transform;
    }

    void Snake::snakeGrow() {
        expand();

        switch(m_snakeDirection.m_currDir) {

            case en::Direction::right :
                m_snakeBody.right();
                break;

            case en::Direction::left :
                m_snakeBody.left();
                break;

            case en::Direction::up :
                m_snakeBody.up();
                break;

            case en::Direction::down :
                m_snakeBody.down();
                break;
        }
    }

    int Snake::head() const noexcept {
        return m_snakeBody.tail();
    }

    int Snake::tail() const noexcept {
        return m_snakeBody.head();
    }

    int Snake::fullSize() const noexcept {
        return m_snakeBody.getSegments().getData().size();
    }

}