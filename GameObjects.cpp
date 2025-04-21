#include "GameObjects.h"

void Inventory::addItem(const std::string &itemName, int quantity) {
    inventory[itemName].name = itemName;
    inventory[itemName].quantity += quantity;
}

void Inventory::removeItem(const std::string &itemName) {
    auto it = inventory.find(itemName);
    if (it != inventory.end()) {
        if (--(it->second.quantity) <= 0) {
            inventory.erase(it);
        }
    } else {
        std::cout << "Item not found in inventory!" << std::endl;
    }
}

void Inventory::printInventory() const {
    if (inventory.empty()) {
        std::cout << "Inventory is empty!" << std::endl;
    } else {
        for (const auto &pair : inventory) {
            pair.second.printItem();
        }
    }
}

void Inventory::saveToFile(const std::string &filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failed to open file for writing.\n";
        return;
    }

    for (const auto &pair : inventory) {
        pair.second.saveToFile(out);
    }
}

void Inventory::loadFromFile(const std::string &filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    inventory.clear();
    while (!in.eof()) {
        Item item = Item::loadFromFile(in);
        if (!item.name.empty()) {
            inventory[item.name] = item;
        }
    }
}
