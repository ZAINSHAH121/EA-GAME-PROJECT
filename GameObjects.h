#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>

class Item {
public:
    std::string name;
    int quantity;

    Item(std::string itemName = "", int itemQuantity = 0)
        : name(std::move(itemName)), quantity(itemQuantity) {}

    void printItem() const {
        std::cout << "Item: " << name << ", Quantity: " << quantity << std::endl;
    }

    void saveToFile(std::ofstream &out) const {
        out << name << ' ' << quantity << '\n';
    }

    static Item loadFromFile(std::ifstream &in) {
        std::string itemName;
        int itemQuantity;
        in >> itemName >> itemQuantity;
        return Item(itemName, itemQuantity);
    }
};

class Inventory {
private:
    std::unordered_map<std::string, Item> inventory;

public:
    void addItem(const std::string &itemName, int quantity);
    void removeItem(const std::string &itemName);
    void printInventory() const;
    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);
};

#endif // GAMEOBJECTS_H
