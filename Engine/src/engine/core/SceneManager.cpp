#include "engine/core/SceneManager.h"
#include "engine/systems/input/inputQueue.h"
#include "engine/render/Window.h"
#include "engine/core/Time.h"
#include "engine/assets/Utilities.h"

namespace Engine::Core {

    void SceneManager::pushScene(std::size_t id) {
        IScene* currentScene = m_scenes[id].get();

        if(currentScene != nullptr) {
            currentScene->onInit();
            m_stack.push_back(currentScene);
        }
    }

    void SceneManager::popScene() {
        if(!m_stack.empty()) {
            m_stack.back()->onExit();
            m_stack.pop_back();
        }
    }

    void SceneManager::update(Engine::Input::i_Queue& events, std::uint64_t tick) {
        if(!m_stack.empty()) {
            m_stack.back()->onUpdate(*this, events, tick);
        }
    }

    void SceneManager::draw(Render::Window& window) {
        if(!m_stack.empty()) {
            m_stack.back()->onRender(window);
        }
    }

    void SceneManager::startGame(Render::Window& window) {
        auto& timer = Time::getTime();
        Input::i_Queue events(1, {'Q'}, {Input::Action::EXIT});

        pushScene(0);

        while(isRunning) {
            timer.startFrame();
            update(events, timer.getGlobalFrameCounter());
            draw(window);
            events.cleanKeyboardBuffer();
            timer.sleepUntil(200);
            Utility::clearScreen();
            window.frameReset();
        }

    }

}