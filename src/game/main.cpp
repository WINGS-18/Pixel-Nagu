#include "engine/render/Window.h"
#include "engine/assets/Utilities.h"
#include "game/entities/Snake.h"
#include "game/entities/Wall.h"
#include "engine/core/Time.h"

int main() {
    Engine::Render::Window<30, 50> gr;
    auto timer = Engine::Time::getTime();
    
    sg::Snake sn(2, 0, 100);
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
    while(true) {
        control = Engine::Utility::keyGiver();
        if(count == 20) {
            sn.snakeGrow();
            count = 0;
        }
        sn.setDirection(control);
        sn.move();
        for(auto& wall : walls) {
            gr.draw(wall.getBody());
        }
        gr.draw(sn.getBody());
        gr.display();
        timer.sleep(200);
        Engine::Utility::clearScreen();
        gr.frameReset();
        count ++;
        //only for testing....
        for(const auto& wall : walls) {
            if(wall.getBody().getGlobalBounds().intersect(Engine::Math::Rect{sn.getCell(sn.head()).m_transform, sn.getCell(sn.head()).m_transform}))
                return 0;
        }
    }

    return 0;

}