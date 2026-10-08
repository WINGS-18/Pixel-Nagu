#include "engine/render/Window.h"
#include "engine/assets/Utilities.h"
#include "game/entities/Snake.h"
#include "game/entities/Wall.h"
#include "engine/core/Time.h"
#include "engine/systems/input/inputQueue.h"

int main() {
    Engine::Render::Window<30, 50> window;
    auto& timer = Engine::Time::getTime();
    Engine::Input::i_Queue events(2);
    
    sg::Snake sn(2, 100);
    std::vector<sg::Wall> walls = {sg::Wall{true, 29, 1}, sg::Wall{true, 29, 1}, sg::Wall{true, 1, 49}, sg::Wall{true, 1, 49}};
    walls[0].setWallPosition(0, 0);
    walls[1].setWallPosition(49, 0);
    walls[2].setWallPosition(0, 0);
    walls[3].setWallPosition(0, 29);

    for(auto& wall : walls) {
        wall.initAll('#');
    }
    
    sn.setup();
    Engine::Input::Action control;

    while(window.isOpen()) {
        timer.startFrame();
        events.registerPress();
        control = events.getPressedKey();
        if(timer.getLocalFrameCounter() == 20) {
            sn.snakeGrow();
            timer.resetLocalFrameCounter();
        }
        sn.setDirection(control);
        sn.move();
        for(auto& wall : walls) {
            window.draw(wall.getBody());
        }
        window.draw(sn.getBody());
        window.display();
        if(control == Engine::Input::Action::EXIT) {
            window.close();
        }
        events.clearInputBuffers();
        timer.sleepUntil(200);
        Engine::Utility::clearScreen();
        window.frameReset();
        //only for testing....
        for(const auto& wall : walls) {
            if(wall.getBody().getGlobalBounds().intersect(Engine::Math::Rect{sn.getCell(sn.head()).m_transform, sn.getCell(sn.head()).m_transform}))
                window.close();
        }

    }

    return 0;

}