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

    void SceneManager::update(Engine::Input::i_Queue& events) {
        if(!m_stack.empty()) {
            m_stack.back()->onUpdate(*this, events);
        }
    }

    void SceneManager::draw(Render::Window<30, 50>& window) {
        if(!m_stack.empty()) {
            m_stack.back()->onRender(window);
        }
    }

    void SceneManager::startGame() {
        auto& timer = Time::getTime();
        Input::i_Queue events(2);
        Render::Window<30, 50> window;

        pushScene(0);

        while(isRunning) {
            timer.startFrame();
            update(events);
            draw(window);
            events.clearInputBuffers();
            timer.sleepUntil(200);
            Utility::clearScreen();
            window.frameReset();
        }

    }

}