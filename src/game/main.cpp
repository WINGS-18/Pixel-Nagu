#include "engine/render-system/GameRender.h"
#include "engine/assets/Utilities.h"
#include <windows.h>

int main() {
    GameRender gr;

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
        gr.insertEntity(w);
        gr.insertEntity(sn);
        gr.display();
        Sleep(70);
        Utility::clearScreen();
        gr.frameReset();
        count ++;
    }

    return 0;

}