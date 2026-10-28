#include "game/entities/Snake.h"
#include <iostream>

namespace sg {

    namespace ec = Engine::Core;
    namespace en = Engine;
    namespace ei = en::Input;

    Snake::Snake(std::size_t initSize, std::size_t reserveSize)
        : m_snakeBody(initSize, reserveSize),
          m_snakeEvents(2, {'W', 'A', 'S', 'D'}, {ei::Action::UP, ei::Action::LEFT, ei::Action::DOWN, ei::Action::RIGHT}) {}

    const ec::Cell& Snake::getCell(int index) const noexcept {
        return m_snakeBody.getSegments()[index];
    }

    ec::Cell& Snake::getCell(int index) noexcept {
        return m_snakeBody.getSegments()[index];
    }

    void Snake::incrementScore() noexcept {
        m_score++;
    }

    int Snake::getScore() const noexcept {
        return m_score;
    }

    const ec::SoftBody& Snake::getBody() const noexcept {
        return m_snakeBody;
    }

    void Snake::setup() {
        m_snakeBody.earlySetup();
    }

    void Snake::setDirection(ei::KeyAction action, std::uint64_t tick) {
        m_snakeDirection.setTheDirection(action, tick);
    }

    bool Snake::didSelfCollide() {
        auto& body = m_snakeBody.getSegments();
        if(body.size() <= 4) {
            return false;
        }

        // i < body.size() - 1 can give critical bug if body.size reaches unit64 limit.
        // i + 1 < body.size() works same.
        for(std::size_t i = 0; i + 1 < body.size(); i++) {
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

    void Snake::shrink(std::size_t size) noexcept {
        m_snakeBody.shrink(size);
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

    /////////////////////////////////////////////////////////////////
    ////////////// FOOD IMPLEMENTATION /////////////////////////////
    ///////////////////////////////////////////////////////////////

    Food::Food(char sprite)
        : m_food(false, 1, 1, sprite) {}

    ec::RigidBody& Food::getBody() noexcept {
        return m_food;
    }

    const ec::RigidBody& Food::getBody() const noexcept {
        return m_food;
    }

    bool Food::wasEaten(Engine::Math::Rect<float> transform) noexcept {
        if(getGlobalBounds().intersect(transform)) {
            m_food.m_active = false;
            return true;
        }
        return false;
    }

    en::Math::Rect<float> Food::getGlobalBounds() const noexcept{
        return m_food.getGlobalBounds();
    }

    void Food::setPosition(float x, float y) {
        if(!m_food.m_active) {
            m_food.setPosition(x, y);
            m_food.m_active = true;
        }
    }

}