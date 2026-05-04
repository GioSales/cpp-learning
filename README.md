# C++ Learning

A C++20 practice workspace containing data structure implementations and a small inventory management system.

## What's inside

| File | Description |
|------|-------------|
| `DynamicArray.h` | Custom dynamic array with manual resize |
| `SinglyLinkedList.h` | Linked list with `unique_ptr`-based ownership |
| `Deque.h` | Templated deque (backed by `std::vector`) |
| `Inventory.h` / `Inventory.cpp` | Inventory system using `std::vector<std::unique_ptr<Item>>` |
| `Item.h` | Plain struct: `Name`, `Quantity`, `Price` |
| `Logger.h` | `LogError()` / `LogInfo()` helpers |
| `main.cpp` | Entry point — runs the inventory menu loop |

## Build

```bash
cmake -B build -G "MinGW Makefiles"
cmake --build build
./build/Learning.exe
```

## Assignments

- `ASSIGNMENT.md` — Inventory system tasks (smart pointers, file I/O, favorites with `shared_ptr`)
- `ASSIGNMENT_OBJECT_POOL.md` — Object pool pattern tasks (templates, free lists, generational handles)

## Requirements

- C++20 compatible compiler
- CMake 3.16+
