#include "entities/Snake.h"

namespace sg {

    int Snake::size() const noexcept {
        return m_snakeBody.getSize();
    }

    const Cell& Snake::getCell(int index) const noexcept {
        return m_snakeBody.getBody()[index];
    }

    void Snake::setup() {
        m_snakeBody.earlySetup();
    }

    void Snake::setDirection(char key) {
        m_snakeDirection.setTheDirection(key);
    }

    void Snake::move() {

        switch(m_snakeDirection.m_currDir) {

            case Direction::right :
                m_snakeBody.moveRight();
                break;

            case Direction::left :
                m_snakeBody.moveLeft();
                break;

            case Direction::up :
                m_snakeBody.moveUp();
                break;

            case Direction::down :
                m_snakeBody.moveDown();
                break;
        }
    }

    void Snake::snakeGrow() {
        auto& bodyzz = m_snakeBody.m_body;

        bodyzz[m_snakeBody.m_size].m_coord = bodyzz[m_snakeBody.m_head].m_coord;
        m_snakeBody.m_head = m_snakeBody.m_size;
        m_snakeBody.m_size++;

        switch(m_snakeDirection.m_currDir) {

            case Direction::right :
                m_snakeBody.right();
                break;

            case Direction::left :
                m_snakeBody.left();
                break;

            case Direction::up :
                m_snakeBody.up();
                break;

            case Direction::down :
                m_snakeBody.down();
                break;
        }
    }

    void Snake::printdd() {
        m_snakeBody.printCoords();
    }

}