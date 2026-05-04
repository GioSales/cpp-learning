//
// Created by Giovanni on 04/04/2026.
//

#include "Inventory.h"

#include <algorithm>
#include <iostream>

#include "Logger.h"

void Inventory::addItem(const std::string& name, int quantity, float price) {
    auto item = std::make_unique<Item>(name,quantity, price);
    this->Items.push_back(std::move(item));
    std::cout << "Item added: " << name << std::endl;
}

void Inventory::removeItem(const std::string& name) {
    auto& items = this->Items;
    auto foundItem = std::find_if(items.begin(), items.end(),
          [&name](const auto& item) { return item->Name == name; });

    if (foundItem != items.end()) {
        this->Items.erase(foundItem);
        Logger::LogInfo("Item removed: " + name);
    }
    else {
        Logger::LogError("Item not found: " + name);
    }

}

void Inventory::listItems() {
    for (auto& item : this->Items) {
        std::cout << item->Name << ". Quant: " << item->Quantity << "; Price: " << item->Price <<  std::endl;
    }
}

Item* Inventory::findItem(const std::string& name) {
    auto& items = this->Items;
    auto foundItem = std::find_if(items.begin(), items.end(),
          [&name](const auto& item) { return item->Name == name; });

    if (foundItem != items.end()) {
        Logger::LogInfo("Found item: " + name);
        return foundItem->get();
    }
    else {
        Logger::LogError("Item not found: " + name);
        return nullptr;
    }
}
