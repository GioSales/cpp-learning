//
// Created by Giovanni on 04/04/2026.
//

#pragma once

#include <string>
#include <utility>

struct Item {
    std::string Name;
    int Quantity;
    float Price;

    Item(std::string name, int quantity, float price) {
        this->Name = std::move(name);
        this->Quantity = quantity;
        this->Price = price;
    }
};
