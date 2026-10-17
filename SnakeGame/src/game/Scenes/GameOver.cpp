#include "engine/core/SceneManager.h"
#include "game/Scenes/GameOver.h"
#include "engine/assets/Utilities.h"
#include "game/Scenes/SceneTypes.h"
#include "engine/systems/input/inputTypes.h"
#include "engine/systems/input/inputQueue.h"
#include <iostream>

namespace sg {

    void GameOver::onInit() {

    }

    void GameOver::onExit() {
        
    }

    void GameOver::onUpdate(Engine::Core::SceneManager& sceneManager, Engine::Input::i_Queue& events, std::uint64_t tick) {

        std::cout << "press any key to return to menu....\n";
        auto key = Engine::Utility::waitKey();

        auto translatedKey = events.translateKey(key);

        if(translatedKey == Engine::Input::Action::EXIT) {
            sceneManager.isRunning = false;
            return;
        }
        
        auto currIdx = static_cast<std::size_t> (sg::SceneEnum::GameOver);

        sceneManager.popScene();
    }

    void GameOver::onRender(Engine::Render::Window<30, 50>& window) {
    
    }

}