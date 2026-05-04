//
// Created by Giovanni on 04/04/2026.
//

#pragma once
#include <memory>
#include <vector>

#include "Item.h"


class Inventory {
    std::vector<std::unique_ptr<Item>> Items;

public:
    void addItem(const std::string& name, int quantity, float price);
    void removeItem(const std::string& name);
    void listItems();
    Item* findItem(const std::string& name);
};
