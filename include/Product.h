/* Folder: include/Product.h */
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// Enum for console colors
enum Color {
    BLACK = 0, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE
};

string colorToString(Color c);

class Product {
protected:
    float price;
    int quantity;
    char productName[50];
    Color color;

public:
    Product();
    Product(const char name[], float p, int qty, Color c);
    void setDetails(const char name[], float p, int qty, Color c);
    void display();
    float getTotalPrice();
};

#endif