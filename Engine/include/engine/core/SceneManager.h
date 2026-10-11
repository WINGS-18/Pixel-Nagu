#pragma once

#include <vector>
#include <memory>
#include "engine/core/IScene.h"

namespace Engine::Core {

    class SceneManager {
    private:
        std::vector<std::unique_ptr<IScene>> m_scenes;
        std::vector<IScene*> m_stack;

    public:
        bool isRunning = true;
        
    
    public:
        SceneManager() = default;

        std::size_t top() const noexcept {return m_stack.size() - 1;}

        template<typename SceneType>
        void registerScene(SceneType id, std::unique_ptr<IScene> scenePtr);
        void pushScene(std::size_t id);
        void popScene();

        void update(Engine::Input::i_Queue& events);
        void draw(Render::Window<30, 50>& window);

        void startGame();

    };

    template<typename SceneType>
    void SceneManager::registerScene(SceneType id, std::unique_ptr<IScene> scenePtr) {
        std::size_t size = static_cast<std::size_t> (id);

        if(size >= m_scenes.size()) {
            m_scenes.resize(size + 1);
        }
        m_scenes[size] = std::move(scenePtr);
    }

}