#include "engine/render/Window.h"
#include "engine/assets/Utilities.h"
#include "game/entities/Snake.h"
#include "game/entities/Wall.h"
#include "engine/core/Time.h"

int main() {
    Engine::Render::Window<30, 50> window;
    auto& timer = Engine::Time::getTime();
    
    sg::Snake sn(1, 0, 100);
    std::vector<sg::Wall> walls = {sg::Wall{true, 29, 1}, sg::Wall{true, 29, 1}, sg::Wall{true, 1, 49}, sg::Wall{true, 1, 49}};
    walls[0].setWallPosition(0, 0);
    walls[1].setWallPosition(49, 0);
    walls[2].setWallPosition(0, 0);
    walls[3].setWallPosition(0, 29);

    for(auto& wall : walls) {
        wall.initAll('#');
    }
    
    sn.setup();
    char control;
    int count = 0;

    while(window.isOpen()) {
        timer.startFrame();
        control = Engine::Utility::keyGiver();
        if(count == 20) {
            sn.snakeGrow();
            count = 0;
        }
        sn.setDirection(control);
        sn.move();
        for(auto& wall : walls) {
            window.draw(wall.getBody());
        }
        window.draw(sn.getBody());
        window.display();
        timer.sleepUntil(200);
        Engine::Utility::clearScreen();
        window.frameReset();
        count ++;
        //only for testing....
        for(const auto& wall : walls) {
            if(wall.getBody().getGlobalBounds().intersect(Engine::Math::Rect{sn.getCell(sn.head()).m_transform, sn.getCell(sn.head()).m_transform}))
                window.close();
        }
    }

    return 0;

}