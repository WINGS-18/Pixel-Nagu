#pragma once

#include <vector>
#include <memory>

namespace Engine::Core {

    class IScene;

    class SceneManger {
    private:
        std::vector<std::unique_ptr<IScene>> m_scenes;
        std::vector<IScene*> m_stack;
        
    
    public:
        SceneManger(std::vector<std::unique_ptr<IScene>> scenes);

        void pushScene();
        void update();
        void draw();

    };

}