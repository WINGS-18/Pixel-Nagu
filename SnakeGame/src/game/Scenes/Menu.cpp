#include "engine/core/SceneManager.h"
#include "game/Scenes/Menu.h"
#include "engine/assets/Utilities.h"
#include <iostream>

namespace sg {

    void MenuScene::onInit() {

    }

    void MenuScene::onExit() {
        
    }

    void MenuScene::onUpdate(Engine::Core::SceneManager& sceneManager, Engine::Input::i_Queue& events) {
        std::cout << "press any key to play.........\n";
        Engine::Utility::waitKey();
        sceneManager.pushScene(static_cast<std::size_t> (sg::SceneEnum::GameplayScene));
    }

    void MenuScene::onRender(Engine::Render::Window<30, 50>& window) {

    }

}