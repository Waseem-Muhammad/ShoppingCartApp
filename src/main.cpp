#include "../include/Menu.h"
#include "../include/Utilities.h"

int main() {
    pMenu menu;
    while (true) {
        menu.displayMenu();
        if (!menu.continueShopping()) {
            break;
        }
    }

    setColor(GREEN);
    printCentered("Exiting...");
    Sleep(3000);
    setColor(MAGENTA);
    printCentered("Thank you for shopping with us!");
    setColor(WHITE);
    system("pause");
    return 0;
}
