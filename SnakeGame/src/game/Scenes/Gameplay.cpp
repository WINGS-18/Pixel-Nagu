#include "game/Scenes/Gameplay.h"
#include "engine/systems/input/inputQueue.h"
#include "engine/assets/Utilities.h"
#include "engine/core/SceneManager.h"
#include "game/Scenes/SceneTypes.h"

namespace sg {

    GameplayScene::GameplayScene(std::string&& sceneName) :
        IScene(std::move(sceneName)),
        m_snake(2, 100), m_food('a') {

        m_walls = {sg::Wall{true, 29, 1}, sg::Wall{true, 29, 1}, sg::Wall{true, 1, 49}, sg::Wall{true, 1, 49}};
    }

    void GameplayScene::onInit() {

        m_food.setPosition(37, 17);

        m_walls[0].setWallPosition(0, 0);
        m_walls[1].setWallPosition(49, 0);
        m_walls[2].setWallPosition(0, 0);
        m_walls[3].setWallPosition(0, 29);
        for(auto& wall : m_walls) {
            wall.initAll('#');
        }

        m_snake.setup();
    }

    void GameplayScene::onUpdate(Engine::Core::SceneManager& sceneManager, Engine::Input::i_Queue& events, std::uint64_t tick) {
        Engine::Math::Rect snakeHead;
        Engine::Input::KeyAction control;
        m_snake.m_snakeEvents.registerPress(tick);
        events.registerPress(tick);
        while(!m_snake.m_snakeEvents.empty()) {
            control = m_snake.m_snakeEvents.getPressedKeyForPollKey();
            m_snake.setDirection(control, tick);
        }
        m_snake.move();
        snakeHead.m_min = m_snake.getCell(m_snake.head()).m_transform;
        snakeHead.m_max = m_snake.getCell(m_snake.head()).m_transform;
        if(m_food.wasEaten(snakeHead)) {
            m_snake.snakeGrow();
            m_snake.incrementScore();
            m_food.setPosition(Engine::Utility::randomInt(10, 48), Engine::Utility::randomInt(5, 29));
        }

        auto systemControl = events.getPressedKeyForPollKey().m_action;

        if(checkCollisionToSlef(sceneManager, systemControl) || checkCollisionToWall(sceneManager, snakeHead)) {
            return;
        }

    }

    void GameplayScene::onRender(Engine::Render::Window<30, 50>& window) {
        for(auto& wall : m_walls) {
            window.draw(wall.getBody());
        }
            
        window.draw(m_food.getBody());
        window.draw(m_snake.getBody());
        window.display();
    }

    void GameplayScene::onExit() {
        Engine::Input::i_Queue::clean_os_buffer();
        m_snake.m_snakeEvents.cleanKeyboardBuffer();
        m_snake.resetScore();
        m_snake.resetDirection();
        m_food.setPosition(37, 17);
        m_snake.shrink(1);
        m_snake.setup();
    }

    bool GameplayScene::checkCollisionToSlef(Engine::Core::SceneManager& sceneManager, Engine::Input::Action control) {
        if(control == Engine::Input::Action::EXIT || m_snake.didSelfCollide()) {
            sceneManager.popScene();
            sceneManager.pushScene(static_cast<std::size_t> (sg::SceneEnum::GameOver));
            return true;
        }
        return false;
    }

    bool GameplayScene::checkCollisionToWall(Engine::Core::SceneManager& sceneManager, Engine::Math::Rect snakeHead) {
        for(const auto& wall : m_walls) {
            if(wall.getBody().getGlobalBounds().intersect(snakeHead)) {
                sceneManager.popScene();
                sceneManager.pushScene(static_cast<std::size_t> (sg::SceneEnum::GameOver));
                return true;
            }
        }
        return false;
    }

}