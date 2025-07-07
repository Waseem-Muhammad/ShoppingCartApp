#ifndef MENU_H
#define MENU_H

#include "Product.h"

class pMenu : public Product {
private:
    Product cart[10];
    int cartIndex;

public:
    pMenu();
    void displayMenu();
    void showCart();
    bool continueShopping();
    bool addToCart(const char name[], float price, int qty, Color color);
    void clearCart();
};

#endif