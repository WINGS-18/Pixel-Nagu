#include "game/entities/Snake.h"

namespace sg {

    namespace ec = Engine::Core;
    namespace en = Engine;

    Snake::Snake(int head, int tail)
        : m_snakeBody(head, tail) {}

    const ec::Cell& Snake::getCell(int index) const noexcept {
        return m_snakeBody.getSegments()[index];
    }

    const ec::SoftBody<100>& Snake::getBody() const noexcept {
        return m_snakeBody;
    }

    void Snake::setup() {
        m_snakeBody.earlySetup();
    }

    void Snake::setDirection(char key) {
        m_snakeDirection.setTheDirection(key);
    }

    void Snake::move() {
        
        switch(m_snakeDirection.m_currDir) {
            
            case en::Direction::right :
                m_snakeBody.moveRight();
            break;
            
            case en::Direction::left :
                m_snakeBody.moveLeft();
                break;

            case en::Direction::up :
                m_snakeBody.moveUp();
                break;

            case en::Direction::down :
                m_snakeBody.moveDown();
                break;
        }
    }

    void Snake::snakeGrow() {
        m_snakeBody.expand();

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
        return m_snakeBody.getHead();
    }

    int Snake::tail() const noexcept {
        return m_snakeBody.getTail();
    }

    int Snake::fullSize() const noexcept {
        return m_snakeBody.getSegments().size();
    }

}