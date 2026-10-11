#pragma once

#include "engine/core/IScene.h"


namespace sg {

    enum class SceneEnum {MenuScene = 0, GameplayScene, GameOver, None};

    class MenuScene : public Engine::Core::IScene {
    public:
        using IScene::IScene;

        virtual void onInit() override;
        virtual void onExit() override;
        virtual void onUpdate(Engine::Core::SceneManager& sceneManager, Engine::Input::i_Queue& events) override;
        virtual void onRender(Engine::Render::Window<30, 50>& window) override;
    };

}