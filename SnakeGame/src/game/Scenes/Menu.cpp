#include "engine/core/SceneManager.h"
#include "game/Scenes/Menu.h"
#include "engine/assets/Utilities.h"
#include "game/Scenes/SceneTypes.h"
#include "engine/systems/input/inputQueue.h"
#include <iostream>

namespace sg {

    void MenuScene::onInit() {

    }

    void MenuScene::onExit() {
        
    }

    void MenuScene::onUpdate(Engine::Core::SceneManager& sceneManager, Engine::Input::i_Queue& events, std::uint64_t tick) {
        std::cout << "press any key to play.........\n";
        auto key = events.getPressedKeyForWaitKey();

        if(key == Engine::Input::Action::EXIT) {
            sceneManager.isRunning = false;
            return;
        }

        sceneManager.pushScene(static_cast<std::size_t> (sg::SceneEnum::GameplayScene));
    }

    void MenuScene::onRender(Engine::Render::Window& window) {

    }

}