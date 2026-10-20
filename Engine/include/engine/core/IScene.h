#pragma once

#include <string>
#include <cstdint>
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
        virtual void onUpdate(SceneManager& sceneManager, Engine::Input::i_Queue& events, std::uint64_t tick) = 0;
        virtual void onRender(Render::Window& window) = 0;
        virtual void onExit() = 0;
    };

}