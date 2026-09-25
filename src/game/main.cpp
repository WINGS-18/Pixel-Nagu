#include "engine/render/Window.h"
#include "engine/assets/Utilities.h"
#include "game/entities/Snake.h"
#include "game/entities/Wall.h"
#include "engine/core/Time.h"

int main() {
    Engine::Render::Window gr;
    auto timer = Engine::Time::getTime();

    sg::Snake sn(2, 0);
    sg::Wall w(159, 0);
    w.setTheWall();
    w.init('#');

    sn.setup();
    char control;
    int count = 0;
    while(true) {
        //sn.printdd();
        control = Engine::Utility::keyGiver();
        if(count == 20) {
            sn.snakeGrow();
            count = 0;
        }
        sn.setDirection(control);
        sn.move();
        gr.draw(w.getBody());
        gr.draw(sn.getBody());
        gr.display();
        timer.sleep(70);
        Engine::Utility::clearScreen();
        gr.frameReset();
        count ++;
    }

    return 0;

}