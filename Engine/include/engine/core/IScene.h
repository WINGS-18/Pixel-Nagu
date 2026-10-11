#pragma once

#include <string>
#include "engine/render/Window.h"

namespace Engine::Input {
    class i_Queue;
}

namespace Engine::Core {

    class SceneManager;

    class IScene {
    public:
        std::string m_sceneName;

        IScene(std::string&& sceneName) 
            : m_sceneName(std::move(sceneName)) {}

        virtual ~IScene() = default;
        virtual void onInit() = 0;
        virtual void onUpdate(SceneManager& sceneManager, Engine::Input::i_Queue& events) = 0;
        virtual void onRender(Render::Window<30, 50>& window) = 0;
        virtual void onExit() = 0;
    };

}