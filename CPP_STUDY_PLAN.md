# C++ Study Plan

Based on the [roadmap.sh/cpp](https://roadmap.sh/cpp) — structured into phases with checklists.
Tick items off as you go. Estimated pace: move on when you can **use** a concept from memory, not just recognize it.

---

## Phase 1 — Fundamentals (Beginner / Start Here)

### 1.1 Introduction & Setup
- [ ] What is C++ and why use it (vs C, vs other languages)
- [ ] Setting up your environment (compiler, IDE — you have CLion + MinGW)
- [ ] Compiling and running your first program

### 1.2 Basic Operations
- [ ] Arithmetic operators (`+`, `-`, `*`, `/`, `%`, increment/decrement)
- [ ] Logical operators (`&&`, `||`, `!`)
- [ ] Bitwise operators (`&`, `|`, `^`, `~`, `<<`, `>>`)

### 1.3 Control Flow & Statements
- [ ] `if` / `else` / `else if`
- [ ] `switch` / `goto`
- [ ] `for` / `while` / `do-while` loops
- [ ] `break` / `continue`

### 1.4 Functions
- [ ] Function declaration vs definition
- [ ] Parameters, return types, overloading
- [ ] Default arguments
- [ ] Static polymorphism (compile-time dispatch via overloading)
- [ ] Operator overloading
- [ ] Lambdas (`[capture](params) { body }`)

### 1.5 Data Types
- [ ] Fundamental types (`int`, `float`, `double`, `char`, `bool`)
- [ ] Static typing vs dynamic typing
- [ ] `auto` keyword (automatic type deduction)
- [ ] `const`, `constexpr`, `static`
- [ ] RTTI (`typeid`, `dynamic_cast` — preview, details in Phase 2)

### 1.6 Pointers & References
- [ ] Raw pointers, the address-of (`&`) and dereference (`*`) operators
- [ ] References vs pointers — when to use which
- [ ] `new` / `delete` and manual memory management
- [ ] Memory leaks and how to detect them
- [ ] Memory model and lifetime of objects (stack vs heap)
- [ ] Smart pointers: `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`

### 1.7 Structuring Code
- [ ] Scope (block, function, file, global)
- [ ] Namespaces
- [ ] Header files (`.h`) vs implementation files (`.cpp`)
- [ ] `#include` guards and `#pragma once`
- [ ] Linking and the one-definition rule (ODR)

### 1.8 Structures & Classes
- [ ] `struct` vs `class` (access specifiers)
- [ ] Constructors, destructors, member initializer lists
- [ ] The Rule of Zero, Three, and Five
- [ ] `this` pointer
- [ ] `static` members
- [ ] Friend functions and classes
- [ ] Multiple inheritance (and diamond problem)

### 1.9 Object-Oriented Programming
- [ ] Inheritance (public, protected, private)
- [ ] Virtual methods and `override` / `final`
- [ ] Virtual tables (vtable) — how dynamic dispatch works under the hood
- [ ] Dynamic polymorphism vs static polymorphism
- [ ] Abstract classes and pure virtual functions

### 1.10 Exception Handling
- [ ] `try` / `catch` / `throw`
- [ ] Standard exception hierarchy (`std::exception`, `std::runtime_error`, etc.)
- [ ] Exit codes (`std::exit`, `main` return values)
- [ ] Access violations and undefined behavior basics

---

## Phase 2 — Intermediate (Pick Next)

### 2.1 Language Concepts
- [ ] Type casting: `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`
- [ ] Undefined behavior (UB) — common traps
- [ ] Argument-dependent lookup (ADL)
- [ ] Name mangling
- [ ] Preprocessor macros (`#define`, `#ifdef`) vs `constexpr` / `inline`

### 2.2 Standard Library + STL
- [ ] **Containers**
  - Sequence: `std::vector`, `std::deque`, `std::list`, `std::array`
  - Associative: `std::map`, `std::set`, `std::unordered_map`, `std::unordered_set`
  - Adaptors: `std::stack`, `std::queue`, `std::priority_queue`
- [ ] **Iterators** — categories (input, output, forward, bidirectional, random access), using iterators with algorithms
- [ ] **Algorithms** — `<algorithm>`: `sort`, `find`, `transform`, `accumulate`, `remove_if`, `min/max`, etc.
- [ ] **iostream** — formatted I/O, file streams (`std::ifstream`/`ofstream`), string streams
- [ ] **Date / Time** — `<chrono>`: clocks, durations, time points
- [ ] **Multithreading** — `<thread>`, `std::mutex`, `std::lock_guard`, `std::async`, `std::future`

### 2.3 Templates
- [ ] Function templates and class templates
- [ ] Template parameters (type, non-type, template template)
- [ ] Variadic templates and parameter packs
- [ ] Template specialization (full and partial)
- [ ] Type traits (`<type_traits>`: `is_integral`, `enable_if`, etc.)
- [ ] SFINAE (Substitution Failure Is Not An Error)

### 2.4 Idioms
- [ ] **RAII** (Resource Acquisition Is Initialization) — the most important C++ idiom
- [ ] **Pimpl** (Pointer to Implementation) — compilation firewalls
- [ ] **CRTP** (Curiously Recurring Template Pattern) — static polymorphism
- [ ] **Copy-and-Swap** — exception-safe assignment operators
- [ ] **Erase-Remove** — the proper way to remove elements from containers
- [ ] **Non-Copyable / Non-Moveable** — deleting special member functions
- [ ] **Copy on Write** — lazy copying strategy

---

## Phase 3 — Advanced (Pick Later)

### 3.1 C++ Standards — Modern Features
- [ ] **C++11/14** — move semantics, `auto`, lambdas, `nullptr`, range-based `for`, `enum class`, `constexpr`
- [ ] **C++17** — structured bindings, `std::optional`, `std::variant`, `if constexpr`, `std::filesystem`, fold expressions
- [ ] **C++20** — concepts, ranges, coroutines, `std::format`, modules, three-way comparison (`<=>`)
- [ ] **C++23** — `std::expected`, `std::print`, deducing `this`, multidimensional `[]` operator

### 3.2 Compilers & Compilation
- [ ] Compilation stages (preprocessing → compilation → assembly → linking)
- [ ] Compiler features and flags (warnings, optimizations)
- [ ] Major compilers: GCC, Clang/LLVM, MSVC, Intel C++, MinGW
- [ ] Name mangling and ABI compatibility

### 3.3 Debugging
- [ ] Understanding debugger messages (segfaults, assertion failures)
- [ ] Debugging symbols (`-g` flag, PDB files)
- [ ] **GDB** — breakpoints, stepping, inspecting variables (Linux/MinGW)
- [ ] **WinDbg** — Windows-native debugging
- [ ] LLDB (Clang's debugger)

---

## Phase 4 — Tooling & Ecosystem (Optional / Learn When Needed)

### 4.1 Build Systems
- [ ] **CMake** — `CMakeLists.txt`, targets, `find_package`, install rules
- [ ] **Make** — Makefiles, rules, variables, patterns
- [ ] **Ninja** — fast build backend (often paired with CMake)

### 4.2 Package Managers
- [ ] **vcpkg** — Microsoft's C++ package manager
- [ ] **Conan** — decentralized C/C++ package manager
- [ ] **Spack** — HPC-focused package manager
- [ ] **NuGet** — .NET-oriented but supports native C++

### 4.3 Working with Libraries
- [ ] Static vs dynamic linking
- [ ] Library inclusion (headers, link flags)
- [ ] Open-source licensing basics

### 4.4 Notable Libraries (pick based on interest)
- [ ] **Boost** — the "second standard library"
- [ ] **fmt / spdlog** — modern formatting and logging
- [ ] **gtest / gmock** — Google's testing framework
- [ ] **Catch2** — BDD-style testing
- [ ] **Qt** — cross-platform GUI framework
- [ ] **OpenCV** — computer vision
- [ ] **protobuf / gRPC** — serialization and RPC
- [ ] **ranges-v3** — range algorithms (pre-C++20)
- [ ] **pybind11** — Python-C++ bindings
- [ ] **TensorFlow / PyTorch C++** — ML inference

---

## Practice Projects

Small projects to solidify each phase:

| Phase | Project | What it exercises |
|-------|---------|-------------------|
| 1 | Console calculator | Control flow, functions, basic I/O |
| 1 | Inventory system *(you have this)* | Classes, smart pointers, file I/O |
| 2 | Custom STL container (e.g. `Vector<T>`) | Templates, iterators, RAII |
| 2 | Thread-safe task queue | Multithreading, `std::mutex`, `std::condition_variable` |
| 2 | Object pool *(you have this)* | Templates, memory management, idioms |
| 3 | JSON parser | C++17 structured bindings, `std::variant`, algorithms |
| 3 | Simple command-line tool using a library | Build systems, linking, package managers |
| 4 | Unit-test your data structures | gtest or Catch2, CMake integration |

---

## Progress Tracking

| Phase | Status | Notes |
|-------|--------|-------|
| 1 — Fundamentals | In progress | Smart pointers, classes, basic OOP done via Inventory |
| 2 — Intermediate | Not started | — |
| 3 — Advanced | Not started | — |
| 4 — Tooling | Partial | CMake basics done (project builds), rest not yet |

---

*Source: [roadmap.sh/cpp](https://roadmap.sh/cpp) — Step by step guide to becoming a C++ developer in 2026*
