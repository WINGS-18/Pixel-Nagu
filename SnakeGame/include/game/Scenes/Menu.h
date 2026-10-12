#pragma once

#include "engine/core/IScene.h"


namespace sg {

    class MenuScene : public Engine::Core::IScene {
    public:
        using IScene::IScene;

        virtual void onInit() override;
        virtual void onExit() override;
        virtual void onUpdate(Engine::Core::SceneManager& sceneManager, Engine::Input::i_Queue& events) override;
        virtual void onRender(Engine::Render::Window<30, 50>& window) override;
    };

}