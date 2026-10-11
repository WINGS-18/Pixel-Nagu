#pragma once

namespace Engine::Core {

class IScene {
public:
    bool m_isActive = false;

    IScene(bool isActive) 
        : m_isActive(isActive) {}

    virtual ~IScene() = default;
    virtual void onInit() = 0;
    virtual void onUpdate() = 0;
    virtual void onRender() = 0;
    virtual void onExit() = 0;
};

}