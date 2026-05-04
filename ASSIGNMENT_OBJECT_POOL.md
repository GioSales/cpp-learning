# Project: Object Pool for Projectiles

Build a generic **object pool** in C++ — a fixed-size container that recycles objects instead of constructing/destructing them every time. This is the core pattern behind bullet systems, particle systems, ECS entity slots, and memory arenas in game engines.

Simulate a tiny shooter: projectiles get "fired" (acquired from the pool), fly for a few ticks, then "expire" (returned to the pool). You'll watch allocations happen **once**, at startup, and never again.

## The scenario

A `Projectile` has:
- `int id`
- `float x, y` (position)
- `float vx, vy` (velocity)
- `int ticksRemaining` (lifetime)
- `bool active`

Each simulation tick, active projectiles move by their velocity and decrement `ticksRemaining`. When it hits zero, they return to the pool.

## Task 1 — The naive version (so you feel the pain)

In `main.cpp`, write a loop that every tick does:
- `new Projectile(...)` for a few new ones
- Moves all existing projectiles
- `delete` any whose lifetime expired

Run it for ~10,000 ticks spawning a handful per tick. This is the baseline. Note: **every shot allocates, every expiration frees.** That's the cost you'll eliminate.

## Task 2 — Define `ObjectPool<T>` as a template class

Create `ObjectPool.h`. The pool owns a fixed-size buffer of `T` (use `std::vector<T>` sized once in the constructor — **no resizing ever**). Constructor takes the capacity.

Public API:
- `T* acquire()` — returns a pointer to an unused slot, or `nullptr` if the pool is full
- `void release(T* obj)` — marks the slot as free again
- `size_t activeCount() const`
- `size_t capacity() const`

Internally, track which slots are free. Start with the simplest possible thing: a parallel `std::vector<bool> _inUse`. Linear scan in `acquire()` is fine for now.

**Constraint:** the pool must never call `new` or `delete` after construction. No allocations in the hot path.

## Task 3 — Wire it into the projectile simulation

Rewrite the loop from Task 1 using `ObjectPool<Projectile>`. Spawning becomes `pool.acquire()` + setting fields. Expiration becomes `pool.release(p)`. Same observable behavior, zero per-shot allocations.

Print `activeCount()` every N ticks so you can see it rise and fall.

## Task 4 — Free-list optimization

The linear scan in `acquire()` is O(n). Replace `_inUse` with a **free list**: a `std::vector<size_t>` (used as a stack) holding indices of free slots. `acquire()` pops, `release()` pushes. Both become O(1).

Think about: why is a stack (LIFO) fine here? Would a queue (FIFO) change anything observable?

## Task 5 — Iteration over active objects

Add a way to walk only the active objects without scanning the whole buffer. Two reasonable designs — pick one and justify it:
- **(a)** Keep a separate `std::vector<T*> _active` updated in `acquire`/`release`.
- **(b)** Swap-and-pop: keep active objects densely packed at the front of the buffer; `release` swaps the released slot with the last active one.

Option (b) is what real engines use (cache-friendly iteration), but it's trickier because **pointers to objects move**. Decide what that means for the public API. Do you hand out `T*`, or an opaque handle (index + generation counter)?

## Task 6 — Generational handles (stretch)

Problem: if code holds a `T*` into the pool, then the slot is released and re-acquired by someone else, the old pointer now silently points to a different object. This is a classic use-after-free-style bug.

Replace raw `T*` with a `Handle { uint32_t index; uint32_t generation; }`. The pool stores a parallel `std::vector<uint32_t> _generations`; `release` increments the slot's generation. `pool.get(handle)` returns `nullptr` if generations don't match.

This is how Unity's ECS, Bevy, EnTT, and every serious engine do entity references.

## Task 7 — Benchmark (stretch)

Use `<chrono>` to time Task 1 (naive new/delete) vs Task 4 (pooled) with the same workload. Print both durations. The gap is the point of this whole assignment — internalize it.

## Concepts practiced
- **Templates** (`template<typename T>`)
- **Placement of allocation** — why "allocate once at startup" is a core game-dev discipline
- **Free lists** as an O(1) allocator primitive
- **Dense vs sparse storage** and cache locality
- **Handles vs pointers** — stable identity across reuse
- **RAII boundaries** — who owns what, when is a destructor *not* the right tool
- Basic benchmarking with `std::chrono`

## Files you'll end up with
```
ObjectPool.h          (template class, header-only)
Projectile.h          (the POD type you'll pool)
main.cpp              (naive version + pooled version + benchmark)
CMakeLists.txt        (updated)
```
