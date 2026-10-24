# 🎮 2D Terminal Game Engine & Snake Client

A custom, zero-dependency 2D game engine built from scratch in modern **C++20** for terminal and console environments, featuring a decoupled monorepo architecture and cache-conscious data structures.

---

## 🏛️ Architecture Overview

The repository is structured as a modular monorepo. The core engine framework lives in `Engine/` and has zero dependencies on game logic. The game client (`SnakeGame/`) consumes the engine as a library, reducing `main.cpp` to just 15 lines of bootstrap code.

```text
snakeeee/
├── Engine/          # Core reusable engine framework
│   ├── core/        # Scene Manager, Timing, Physics Bodies (Cell, RigidBody, SoftBody)
│   ├── math/        # Vector2C, Rect (AABB), Extents, Direction system
│   ├── render/      # Double-buffered Window & Terminal Blitter
│   ├── structures/  # Cache-friendly contiguous RingBuffer & FlatArray
│   └── systems/     # Hardware-level Input Action Mapping (i_Queue)
├── SnakeGame/       # Game client implementation
│   ├── entities/    # Snake, Wall, Food
│   ├── Scenes/      # MenuScene, GameplayScene, GameOver
│   └── main.cpp     # 15-line engine bootstrap
└── Makefile         # Unified C++20 cross-directory build
```

---

## ⚙️ Core Engineering Highlights

### 1. Data-Oriented Memory over Pointer Chasing
Instead of node allocations or scattered linked lists, all snake segments and input events are backed by a custom contiguous circular buffer (`RingBuffer<T>`). By mapping circular physical wrap-arounds to logical indices `(m_head + index) % size`, self-collision checks run as a single cache-friendly linear scan across L1/L2 cache lines.

### 2. Hardware Input Polling vs. OS Text Streams
Legacy terminal input (`_getch`) suffers from a 500ms typematic repeat lag and cannot handle simultaneous keypresses. The engine bypasses the terminal stream and directly polls hardware states via Win32 `GetAsyncKeyState`, routing inputs into isolated player channels (`i_Queue`) with discrete monotonic frame tick-stamping.

### 3. Polymorphic Scene Stack
State navigation (`Menu` → `Gameplay` → `GameOver`) is handled by a polymorphic stack (`IScene` / `SceneManager`). Virtual dispatch is strictly isolated to the scene boundary ($O(1)$ vtable lookup per frame), guaranteeing that entity inner loops remain non-virtual and compiler-inlinable.

### 4. Flicker-Free Terminal Blitting
Terminal cursor tearing is completely eliminated. Game entities draw into a flattened 2D grid (`FlattArray`), which is packed into a contiguous string buffer (`FlattString`) and flushed to standard output in a single atomic write.

---

## 🎮 Controls

| Context | Key | Action |
| :--- | :--- | :--- |
| **Menu / Game Over** | Any Key | Start / Return to Menu |
| **Menu / Game Over** | `Q` / `Shift + Q` | Exit Game |
| **Gameplay** | `W` / `A` / `S` / `D` | Move Up / Left / Down / Right |
| **Gameplay** | `Q` | Instant Exit to Game Over |

---

## 🚀 Building & Running

### Prerequisites
* GCC / G++ (Supporting **C++20**)
* Make (`mingw32-make` on Windows)

### Build & Run
```bash
# Clone the repository
git clone https://github.com/WINGS-18/snakeeee.git
cd snakeeee

# Compile with C++20 optimizations (-O3)
mingw32-make

# Run the game
.\snake_game.exe
```

---

## 🗺️ Roadmap
- [x] Decoupled Engine / Client monorepo
- [x] Contiguous RingBuffer with logical indexing
- [x] Hardware input polling & tick stamping
- [x] Polymorphic Scene Manager
- [x] Resolution-agnostic runtime renderer
- [ ] Extract cache-friendly data structures into standalone **CTL** (Cache Template Library)
- [ ] 2-Player local multiplayer game (**Tag**) with continuous floating-point physics