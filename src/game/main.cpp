#include "engine/render/Window.h"
#include "engine/assets/Utilities.h"
#include <windows.h>

int main() {
    render::Window gr;

    sg::Snake sn(2, 0);
    sg::Wall w(159, 0);
    w.setTheWall();
    w.init('#');

    sn.setup();
    char control;
    int count = 0;
    while(true) {
        //sn.printdd();
        control = Utility::keyGiver();
        if(count == 20) {
            sn.snakeGrow();
            count = 0;
        }
        sn.setDirection(control);
        sn.move();
        gr.draw(w);
        gr.draw(sn);
        gr.display();
        Sleep(70);
        Utility::clearScreen();
        gr.frameReset();
        count ++;
    }

    return 0;

}