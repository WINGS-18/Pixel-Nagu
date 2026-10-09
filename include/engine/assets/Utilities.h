/**
 * @file Utilities.h
 * This header provides many functions that are used to
 * manipulate the terminal.
 * Ex: color change, hide cursor, clear screen etc.,
 * It uses ANSI codes.
 */

#pragma once

namespace Engine {
    namespace Utility {

        void reset();      
        void green();  
        void red();  

        void clearScreen();   
        void hideCursor();
        void showCursor();  

        char pollKey();    //non-blockingS
        char waitKey();    //blocks the program untill key is pressed.

        void displayFinalScore(int score);

        int randomInt(int min, int max);
    }
}