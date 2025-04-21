#include <iostream>
#include "GameObjects.h"

int main() {
    Inventory inv;

    // Load saved inventory if exists
    inv.loadFromFile("inventory.txt");

    inv.addItem("Football", 3);
    inv.addItem("Helmet", 1);
    inv.addItem("Jersey", 2);

    std::cout << "Initial Inventory:" << std::endl;
    inv.printInventory();

    inv.removeItem("Football");
    inv.removeItem("Football");
    inv.removeItem("Football");
    inv.removeItem("Helmet");

    std::cout << "\nUpdated Inventory:\n";
    inv.printInventory();

    // Save updated inventory
    inv.saveToFile("inventory.txt");

    return 0;
}
