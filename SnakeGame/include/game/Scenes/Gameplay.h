#pragma once

#include "engine/core/IScene.h"
#include "game/entities/Snake.h"
#include "game/entities/Wall.h"

namespace sg {

    class GameplayScene : public Engine::Core::IScene {
    private:
        Snake m_snake;
        std::vector<Wall> m_walls;
        Food m_food;

    public:
        GameplayScene(std::string&& sceneName);

        virtual void onInit() override;
        virtual void onUpdate(Engine::Core::SceneManager& sceneManager, Engine::Input::i_Queue& events) override;
        virtual void onRender(Engine::Render::Window<30, 50>& window) override;
        virtual void onExit() override;

    };

}