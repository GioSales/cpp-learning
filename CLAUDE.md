# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

A C++ learning/practice workspace containing multiple data structure implementations and a small inventory management system. Built with **CMake** and **C++20**, developed in CLion.

## Build & Run

```bash
# Build (from project root)
cmake -B build -G "MinGW Makefiles"   # or whatever generator CLion uses
cmake --build build

# Run
./build/Learning.exe
```

There are no tests, linter, or CI configured — this is a learning sandbox. All code compiles into a single `Learning` executable via `CMakeLists.txt`.

## Architecture

Single-executable project. Each data structure is a **header-only** class (except `Inventory` which has a `.h`/`.cpp` pair). All files are listed explicitly in `CMakeLists.txt` — when adding new `.cpp` files, update it.

### Core modules

| File | Purpose |
|------|---------|
| `main.cpp` | Entry point — runs the inventory menu loop |
| `Inventory.h` / `Inventory.cpp` | Inventory system using `std::vector<std::unique_ptr<Item>>` |
| `Item.h` | Plain struct: `Name`, `Quantity`, `Price` |
| `Logger.h` | Inline namespace with `LogError()` / `LogInfo()` helpers |
| `DynamicArray.h` | Custom dynamic array with manual resize (doubles capacity) |
| `SinglyLinkedList.h` | Linked list with `unique_ptr`-based ownership, head + tail pointers |
| `Deque.h` | Templated deque declaration (backed by `std::vector`) |
| `cmake-build-debug/TextInputApi.h` | Inline helpers: `TryReadInt()`, `TryReadFloat()` for safe console input |

### Assignments

Two assignment specs live in the repo root:
- **`ASSIGNMENT.md`** — Inventory system tasks (smart pointers, file I/O, favorites with `shared_ptr`)
- **`ASSIGNMENT_OBJECT_POOL.md`** — Object pool pattern tasks (templates, free lists, generational handles, benchmarking)

## Interaction Style

This is a **learning project**. Act as a teacher, not a code writer:
- **Guide the user toward solutions** using questions, hints, and analogies — don't hand out complete implementations unless explicitly asked.
- Ask "what do you think should happen here?" before explaining. Let the user reason first.
- When the user is stuck, give progressively stronger hints before showing code.
- Exception: if the user explicitly asks for a solution or says "just write it", provide it directly. Tedious/boilerplate code doesn't need the Socratic treatment.

## C++ Study Streak

Track daily C++ study consistency. Update when user works on C++ in this project.

- **Streak Rules:** When user sends a C++ related prompt, mark today as a study day. If studied yesterday, increment streak. If not, reset to 1.
- **Current Streak:** tracked in memory (`cpp_study_streak.md`)

## Conventions

- **C++20 standard** (`CMAKE_CXX_STANDARD 20`)
- Header-only classes use `#pragma once` or `#ifndef` guards
- Smart pointers used throughout (`std::unique_ptr` for ownership, raw pointers for non-owning access)
- Member variables use PascalCase (matching the existing style: `Items`, `Name`, `Quantity`)
- `ASSIGNMENT*.md` files define the learning tasks — check them to understand what each module is working toward
