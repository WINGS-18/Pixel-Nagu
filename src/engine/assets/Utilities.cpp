#include "engine/assets/Utilities.h"
#include <iostream>
#include <conio.h>

void Engine::Utility::reset() {
    std::cout << "\033[0m";
}

void Engine::Utility::red() {
    std::cout << "\033[31m";
}

void Engine::Utility::green() {
    std::cout << "\033[92m";
}

void Engine::Utility::clearScreen() {
    std::cout << "\033[2J\033[H";
}

void Engine::Utility::hideCursor() {
    std::cout << "\033[?25l";
}

void Engine::Utility::showCursor() {
    std::cout << "\033[?25h";
}

char Engine::Utility::keyGiver() {
    if(_kbhit())
        return _getch();
    else
        return '\0';
}

char Engine::Utility::pressKey() {
    return _getch();
}

void Engine::Utility::displayFinalScore(int score) {

    Utility::clearScreen();
    std::cout << "========================================\n";
    std::cout << "||          <--GAME OVER-->           ||\n";
    std::cout << "========================================\n\n";
    
    std::cout << "       Final Score: [ " << score << " ] \n\n";
    
    std::cout << "========================================\n";
    std::cout << "||   Press 'e' to return to menu...   ||\n";
    std::cout << "========================================\n";

}