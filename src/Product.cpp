#include "../include/Product.h"
#include <iomanip>
#include <cstring>

Product::Product() {
    price = 0.0;
    quantity = 0;
    strcpy(productName, "");
    color = BLACK;
}

Product::Product(const char name[], float p, int qty, Color c) {
    strcpy(productName, name);
    price = p;
    quantity = qty;
    color = c;
}

void Product::setDetails(const char name[], float p, int qty, Color c) {
    strcpy(productName, name);
    price = p;
    quantity = qty;
    color = c;
}

void Product::display() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    cout << "Product: " << productName
         << " | Quantity: " << quantity
         << " | Price: " << price << " PKR"
         << " | Color: " << colorToString(color) << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

float Product::getTotalPrice() {
    return price * quantity;
}

string colorToString(Color c) {
    switch (c) {
        case RED: return "Red";
        case BLUE: return "Blue";
        case GREEN: return "Green";
        case BLACK: return "Black";
        case WHITE: return "White";
        case MAGENTA: return "Magenta";
        case YELLOW: return "Yellow";
        case CYAN: return "Cyan";
        default: return "Unknown";
    }
}