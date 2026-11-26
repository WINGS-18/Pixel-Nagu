#include "game/entities/Snake.h"
#include "engine/math/vector2C.h"
#include "engine/systems/input/inputTypes.h"

namespace sg {

    namespace en = Engine;
    namespace ei = en::Input;
    

    Snake::Snake(std::size_t capacity)
        : m_segments(capacity),
          m_snakeEvents(2, {'W', 'A', 'S', 'D'}, {ei::Action::UP, ei::Action::LEFT, ei::Action::DOWN, ei::Action::RIGHT}) {}

    void Snake::incrementScore() noexcept {
        m_score++;
    }

    int Snake::getScore() const noexcept {
        return m_score;
    }

    void Snake::setup() {
        m_currDirection = ei::Action::RIGHT;
        m_segments.push({2, 1});
    }

    void Snake::setDirection(ei::KeyAction action, std::uint64_t tick) {
        switch (action.m_action) {
            
            case ei::Action::RIGHT :
                if(!opposite(m_currDirection))  m_currDirection = action.m_action;
                break;

            
            case ei::Action::LEFT :
                if(!opposite(m_currDirection))  m_currDirection = action.m_action;
                break;

            
            case ei::Action::UP :
                if(!opposite(m_currDirection))  m_currDirection = action.m_action;
                break;

            
            case ei::Action::DOWN :
                if(!opposite(m_currDirection))  m_currDirection = action.m_action;
                break;

            
            case ei::Action::EXIT :
                break;
            
            case ei::Action::NONE :
                break;

            default :
                break;
            
        }
    }

    bool Snake::opposite(ei::Action action) {
        if(action == ei::Action::RIGHT && m_currDirection == ei::Action::LEFT) return true;
        if(action == ei::Action::LEFT && m_currDirection == ei::Action::RIGHT) return true;
        if(action == ei::Action::UP && m_currDirection == ei::Action::DOWN) return true;
        if(action == ei::Action::DOWN && m_currDirection == ei::Action::UP) return true;
        return false;
    }

    bool Snake::didSelfCollide() {
        if(m_segments.size() <= 4) {
            return false;
        }

        // i < body.size() - 1 can give critical bug if body.size reaches unit64 limit.
        // i + 1 < body.size() works same.
        for(std::size_t i = 0; i + 1 < m_segments.size(); i++) {
            if(m_segments[i] == m_segments.back()) {
                return true;
            }
        }

        return false;
    }

    void Snake::moveSnake(Engine::Math::vector2i directionVector) noexcept {
        auto newHead = m_segments.back() + directionVector;
        
        if(!m_didGrow) {
            m_segments.pop();
        }else {
            m_didGrow = false;
        }

        m_segments.push(newHead);
    }

    void Snake::move() noexcept {
        
        switch(m_currDirection) {
            
            case ei::Action::RIGHT :
                moveSnake({1, 0});
                break;
            
            case ei::Action::LEFT :
                moveSnake({-1, 0});
                break;

            case ei::Action::UP :
                moveSnake({0, -1});
                break;

            case ei::Action::DOWN :
                moveSnake({0, 1});
                break;

            default :
                break;
        }
    }


    void Snake::clear() noexcept {
        m_segments.clear();
    }

    void Snake::snakeAteFood() {
        m_didGrow = true;
    }

    /////////////////////////////////////////////////////////////////
    ////////////// FOOD IMPLEMENTATION /////////////////////////////
    ///////////////////////////////////////////////////////////////

    Food::Food(std::initializer_list<std::initializer_list<char>> sprite)
        : m_food(sprite) {}

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
