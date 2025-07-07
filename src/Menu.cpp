#include "../include/Menu.h"
#include "../include/Utilities.h"
#include <cstdlib>
#include <chrono>
#include <thread>

const int screenWidth = 80;

pMenu::pMenu() {
    cartIndex = 0;
}

bool pMenu::addToCart(const char name[], float price, int qty, Color color) {
    if (qty >= 10) {
        setColor(RED);
        printCentered("Cart is full (max 10 items). Cannot add more!");
        setColor(WHITE);
        system("pause");
        clearScreen();
        return false;
    }

    if (qty <= 0) {
        setColor(RED);
        printCentered("Quantity must be at least 1!");
        setColor(WHITE);
        system("pause");
        clearScreen();
        return false;
    }

    cart[cartIndex++].setDetails(name, price, qty, color);
    return true;
}

void pMenu::clearCart() {
    cartIndex = 0;
    setColor(GREEN);
    printCentered("Cart cleared successfully!");
    setColor(WHITE);
    system("pause");
    clearScreen();
}

void pMenu::showCart() {
    if (cartIndex == 0) {
        setColor(RED);
        printCentered("Your cart is empty.");
        setColor(WHITE);
        system("pause");
        clearScreen();
        return;
    }

    float totalBill = 0;
    setColor(GREEN);
    printCentered("---------- Cart Details ----------");
    for (int i = 0; i < cartIndex; i++) {
        cart[i].display();
        totalBill += cart[i].getTotalPrice();
    }
    cout << endl;
    printCentered("----------------------------------");
    printCentered("Calculating Bill...Please Wait...");
    Sleep(3000);
    printCentered("----------------------------------");
    cout << "Total Bill: " << totalBill << " PKR\n";
    setColor(WHITE);
    system("pause");
    clearScreen();
}

bool pMenu::continueShopping() {
    char choice;
    cout << "\nDo you want to continue shopping? (Y/N): ";
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}
void pMenu::displayMenu() {
    clearScreen();
    setColor(MAGENTA);
    printCentered("------------***Welcome to IWY Mart***------------");
    setColor(YELLOW);
    printCentered("--------------Main Menu-----------");
    setColor(CYAN);
    printCentered("1. Phones");
    printCentered("2. Speakers");
    printCentered("3. Laptops");
    printCentered("4. USB");
    printCentered("5. Chargers");
    printCentered("6. View Cart");
    printCentered("7. Clear Cart");
    printCentered("8. Exit");

    setColor(WHITE);
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    clearScreen();

    int subChoice, qty;
    bool added = false;

    switch (choice) {
    case 1:
        setColor(CYAN);
        printCentered("Available Phones:");
        setColor(WHITE);
        printCentered("1. iPhone 13 - 50000 PKR");
        printCentered("2. iPhone 14 - 70000 PKR");
        printCentered("3. iPhone 15 - 100000 PKR");
        printCentered("4. iPhone 16 - 120000 PKR");
        cout << "Enter your choice: ";
        cin >> subChoice;
        cout << "Enter quantity: ";
        cin >> qty;
        clearScreen();
        switch (subChoice) {
            case 1: added = addToCart("iPhone 13", 50000, qty, CYAN); break;
            case 2: added = addToCart("iPhone 14", 70000, qty, WHITE); break;
            case 3: added = addToCart("iPhone 15", 100000, qty, BLACK); break;
            case 4: added = addToCart("iPhone 16", 120000, qty, BLACK); break;
            default:
                setColor(RED);
                printCentered("Invalid choice!");
                setColor(WHITE);
                system("pause");
                clearScreen();
                return;
        }
        break;

    case 2:
        setColor(CYAN);
        printCentered("Available Speakers:");
        setColor(WHITE);
        printCentered("1. Audionic - 5000 PKR");
        printCentered("2. Faster - 4500 PKR");
        printCentered("3. Edifier - 3000 PKR");
        printCentered("4. JBL - 2500 PKR");
        cout << "Enter your choice: ";
        cin >> subChoice;
        cout << "Enter quantity: ";
        cin >> qty;
        clearScreen();
        switch (subChoice) {
            case 1: added = addToCart("Audionic", 5000, qty, BLACK); break;
            case 2: added = addToCart("Faster", 4500, qty, RED); break;
            case 3: added = addToCart("Edifier", 3000, qty, BLUE); break;
            case 4: added = addToCart("JBL", 2500, qty, BLACK); break;
            default:
                setColor(RED);
                printCentered("Invalid choice!");
                setColor(WHITE);
                system("pause");
                clearScreen();
                return;
        }
        break;

    case 3:
        setColor(CYAN);
        printCentered("Available Laptops:");
        setColor(WHITE);
        printCentered("1. HP - 150000 PKR");
        printCentered("2. Lenovo - 70000 PKR");
        printCentered("3. Dell - 130000 PKR");
        printCentered("4. Acer - 120000 PKR");
        cout << "Enter your choice: ";
        cin >> subChoice;
        cout << "Enter quantity: ";
        cin >> qty;
        clearScreen();
        switch (subChoice) {
            case 1: added = addToCart("HP", 150000, qty, GREEN); break;
            case 2: added = addToCart("Lenovo", 70000, qty, BLACK); break;
            case 3: added = addToCart("Dell", 130000, qty, BLACK); break;
            case 4: added = addToCart("Acer", 120000, qty, WHITE); break;
            default:
                setColor(RED);
                printCentered("Invalid choice!");
                setColor(WHITE);
                system("pause");
                clearScreen();
                return;
        }
        break;

    case 4:
        setColor(CYAN);
        printCentered("Available USBs:");
        setColor(WHITE);
        printCentered("1. 10GB - 1000 PKR");
        printCentered("2. 20GB - 2000 PKR");
        printCentered("3. 30GB - 3000 PKR");
        printCentered("4. 40GB - 4000 PKR");
        cout << "Enter your choice: ";
        cin >> subChoice;
        cout << "Enter quantity: ";
        cin >> qty;
        clearScreen();
        switch (subChoice) {
            case 1: added = addToCart("10GB USB", 1000, qty, RED); break;
            case 2: added = addToCart("20GB USB", 2000, qty, BLUE); break;
            case 3: added = addToCart("30GB USB", 3000, qty, GREEN); break;
            case 4: added = addToCart("40GB USB", 4000, qty, WHITE); break;
            default:
                setColor(RED);
                printCentered("Invalid choice!");
                setColor(WHITE);
                system("pause");
                clearScreen();
                return;
        }
        break;

    case 5:
        setColor(CYAN);
        printCentered("Available Chargers:");
        setColor(WHITE);
        printCentered("1. C-type charger - 1000 PKR");
        printCentered("2. B-type charger - 800 PKR");
        printCentered("3. HP laptop charger - 3000 PKR");
        printCentered("4. Dell laptop charger - 4000 PKR");
        printCentered("5. Lenovo laptop charger - 5000 PKR");
        printCentered("6. Acer laptop charger - 7000 PKR");
        cout << "Enter your choice: ";
        cin >> subChoice;
        cout << "Enter quantity: ";
        cin >> qty;
        clearScreen();
        switch (subChoice) {
            case 1: added = addToCart("C-type charger", 1000, qty, BLACK); break;
            case 2: added = addToCart("B-type charger", 800, qty, WHITE); break;
            case 3: added = addToCart("HP laptop charger", 3000, qty, BLACK); break;
            case 4: added = addToCart("Dell laptop charger", 4000, qty, BLACK); break;
            case 5: added = addToCart("Lenovo laptop charger", 5000, qty, BLACK); break;
            case 6: added = addToCart("Acer laptop charger", 7000, qty, BLACK); break;
            default:
                setColor(RED);
                printCentered("Invalid choice!");
                setColor(WHITE);
                system("pause");
                clearScreen();
                return;
        }
        break;

    case 6:
        showCart();
        return;

    case 7:
        clearCart();
        return;

    case 8:
        setColor(GREEN);
        printCentered("Thank you for shopping with us!");
        setColor(WHITE);
        exit(0);

    default:
        setColor(RED);
        printCentered("Invalid menu choice!");
        setColor(WHITE);
        system("pause");
        clearScreen();
        return;
    }

    if (added) {
        setColor(YELLOW);
        printCentered("Adding to cart...");
        Sleep(2000);
        printCentered("Item added successfully!");
        setColor(WHITE);
        system("pause");
        showCart();
    }
}
