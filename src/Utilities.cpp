#include "../include/Utilities.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>

const int screenWidth = 80;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}

void printCentered(const string& text) {
    int padding = (screenWidth - (int)text.length()) / 2;
    if (padding > 0) std::cout << std::string(padding, ' ') << text << std::endl;
    else std::cout << text << std::endl;
}
