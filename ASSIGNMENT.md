# Project: Inventory Management System

A text-based inventory system for a shop. The user can add items, remove items, list them, search, and quit.

## The Items

Each item in the inventory should have:
- A **name** (`std::string`)
- A **quantity** (`int`)
- A **price** (`float`)

## Task 1 — Define the struct

Create an `Item` struct in its own header file (`Item.h`). Give it the three fields above and a constructor.

## Task 2 — The Inventory class

Create an `Inventory` class (`.h` and `.cpp`) that internally stores items using a `std::vector` of `std::unique_ptr<Item>`. It should have methods for:
- `addItem(name, quantity, price)` — creates a new item and adds it
- `removeItem(name)` — finds and removes an item by name
- `listItems()` — prints all items with their details
- `findItem(name)` — returns a pointer to an item (think about what kind of pointer to return here — raw? reference? `shared_ptr`?)

This is where you'll get practice with `std::unique_ptr` and ownership semantics.

## Task 3 — The menu loop

In `main.cpp`, create a loop that shows a menu:
```
1. Add item
2. Remove item
3. List items
4. Search item
5. Quit
```
Read the user's choice and call the appropriate `Inventory` method. This practices input handling and program flow.

## Task 4 — Split files properly

Make sure each class has its own `.h` / `.cpp` pair with proper include guards. Update `CMakeLists.txt` to compile all the `.cpp` files.

## Task 5 — Add an "update quantity" feature

Add a method to `Inventory` that lets the user change the quantity of an existing item. Use `findItem()` internally — this will test whether the pointer/reference design from Task 2 actually works for mutation.

## Task 6 — Introduce `shared_ptr`

Add a "favorites" feature: the user can mark items as favorites, stored in a separate `std::vector<std::shared_ptr<Item>>`. This means converting storage from `unique_ptr` to `shared_ptr` so that both the main inventory and the favorites list can point to the same item. Think about **why** `unique_ptr` no longer works here and what changes.

## Task 7 — Save & Load (bonus stretch)

Write the inventory to a text file on quit and load it back on startup using `<fstream>`. This introduces file I/O.

## Concepts practiced
- Structs and classes
- Header/source file separation
- `std::vector`
- `std::unique_ptr` and `std::shared_ptr` (and when to use which)
- Passing by reference vs pointer
- Loops and user input
- File I/O (Task 7)
