#include <iostream>
#include <cassert>

#include "Deque.h"
#include "Inventory.h"
#include "Item.h"
#include "Logger.h"

void PrintMenuOptions() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Add item" << std::endl;
    std::cout << "2. Remove item" << std::endl;
    std::cout << "3. List items" << std::endl;
    std::cout << "4. Search item" << std::endl;
    std::cout << "5. Quit" << std::endl;
}

void RunInventoryMenu() {
    Inventory inventory;

    std::string itemName;
    float itemPrice;
    int itemQuant;

    while (true) {
        std::cout.flush();
        PrintMenuOptions();

        std::string input;
        std::getline(std::cin, input);

        int choice;

        try {
            choice = std::stoi(input);
        } catch (...) {
            std::cout << "Invalid input" << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Item name:" << std::endl;
                std::cin >> itemName;
                std::cout << "Item price:" << std::endl;
                std::cin >> itemPrice;
                std::cout << "Item quantity:" << std::endl;
                std::cin >> itemQuant;
                inventory.addItem(itemName, itemQuant, itemPrice);
                break;
            case 2:
                std::cout << "Name of item to remove:" << std::endl;
                std::cin >> itemName;
                inventory.removeItem(itemName);
                break;
            case 3:
                std::cout << "Items:" << std::endl;
                inventory.listItems();
                break;
            case 4:
                std::cout << "Name of item to search:" << std::endl;
                std::cin >> itemName;
                inventory.findItem(itemName);
                break;
            case 5:
                std::cout << "Quitting..." << std::endl;
                return;
            default:
                Logger::LogError("Invalid choice: " + std::to_string(choice));
                break;
        }
    }
}

void TestDeque() {
    std::cout << "=== Deque Tests ===\n\n";

    // --- Initialization ---
    std::cout << "--- Initialization ---\n";
    Deque dq;
    assert(dq.isEmpty() && "New deque should be empty");
    assert(dq.size() == 0 && "New deque should have size 0");
    std::cout << "PASS: New deque is empty with size 0\n\n";

    // --- Enqueue at rear, dequeue from front ---
    std::cout << "--- Enqueue rear / Dequeue front ---\n";
    dq.push_back(10);
    assert(dq.size() == 1);
    assert(dq.front() == 10);
    assert(dq.back() == 10);
    dq.pop_front();
    assert(dq.isEmpty() && "Should be empty after push_back then pop_front");
    std::cout << "PASS: push_back then pop_front leaves deque empty\n\n";

    // --- Dequeue front, enqueue rear (rotate) ---
    std::cout << "--- Rotate: pop_front then push_back ---\n";
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    // deque: front→[1, 2, 3]←back
    int val = dq.front();
    dq.pop_front();
    dq.push_back(val);
    // deque: front→[2, 3, 1]←back
    assert(dq.size() == 3 && "Size unchanged after rotation");
    assert(dq.front() == 2 && "Front should be 2 after rotation");
    assert(dq.back() == 1 && "Back should be 1 after rotation");
    std::cout << "PASS: Rotation preserves size and changes order\n\n";

    // --- Size tracking ---
    std::cout << "--- Size ---\n";
    Deque dq2;
    assert(dq2.size() == 0);
    dq2.push_front(42);
    assert(dq2.size() == 1 && "Size should increase by 1 after push");
    dq2.push_back(99);
    assert(dq2.size() == 2 && "Size should increase by 1 after push");
    dq2.pop_front();
    assert(dq2.size() == 1 && "Size should decrease by 1 after pop");
    dq2.pop_back();
    assert(dq2.size() == 0 && "Size should be 0 after all pops");
    std::cout << "PASS: Size tracks correctly\n\n";

    // --- Empty check ---
    std::cout << "--- Empty Check ---\n";
    Deque dq3;
    assert(dq3.isEmpty());
    dq3.push_back(5);
    dq3.push_back(6);
    dq3.push_front(4);
    assert(!dq3.isEmpty());
    dq3.pop_front();
    dq3.pop_front();
    dq3.pop_back();
    assert(dq3.isEmpty() && "Should be empty after removing all elements");
    std::cout << "PASS: isEmpty reports correctly after draining\n\n";

    // --- Front/Back methods ---
    std::cout << "--- Front / Back Access ---\n";
    Deque dq4;
    dq4.push_front(20);   // [20]
    dq4.push_back(30);    // [20, 30]
    dq4.push_front(10);   // [10, 20, 30]
    assert(dq4.front() == 10 && "Front should be last push_front value");
    assert(dq4.back() == 30 && "Back should be last push_back value");
    std::cout << "PASS: front() and back() return correct elements\n\n";

    // --- Pop from back ---
    std::cout << "--- pop_back ---\n";
    Deque dq5;
    dq5.push_back(1);
    dq5.push_back(2);
    dq5.push_back(3);
    dq5.pop_back();
    assert(dq5.back() == 2 && "Back should be 2 after popping 3");
    assert(dq5.size() == 2);
    dq5.pop_back();
    dq5.pop_back();
    assert(dq5.isEmpty() && "Should be empty after popping all from back");
    std::cout << "PASS: pop_back works correctly\n\n";

    std::cout << "=== All Deque tests passed! ===\n";
}

int main() {
    TestDeque();
    return 0;
}
