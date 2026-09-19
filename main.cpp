#include "render-system/GameRender.h"
#include "engine/assets/Utilities.h"
#include <windows.h>

int main() {
    GameRender gr;

    sg::Snake sn;

    sn.setup();
    char control;
    int count = 0;
    while(true) {
        // sn.printdd();
    control = Utility::keyGiver();
    if(count == 20) {
        sn.snakeGrow();
        count = 0;
    }else {
        sn.setDirection(control);
    }
    sn.move();
    gr.insertEntity(sn);
    gr.display();
    Sleep(100);
    Utility::clearScreen();
    gr.frameReset();
    count ++;
    }

    return 0;

}