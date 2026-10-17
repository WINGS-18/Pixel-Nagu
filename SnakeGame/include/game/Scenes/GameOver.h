#pragma once

#include "engine/core/IScene.h"
#include "game/entities/Snake.h"

namespace sg {

    class GameOver : public Engine::Core::IScene {
    public:
        using IScene::IScene;

        virtual void onInit() override;
        virtual void onExit() override;
        virtual void onUpdate(Engine::Core::SceneManager& sceneManager, Engine::Input::i_Queue& events, std::uint64_t tick) override;
        virtual void onRender(Engine::Render::Window<30, 50>& window) override;
    };

}