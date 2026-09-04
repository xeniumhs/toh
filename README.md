# 🗼 Tower of Hanoi — TOH

A graphical **Tower of Hanoi** puzzle game developed in **C++** as a group project. The game provides an interactive GUI where players can move disks between pegs using the mouse while following the classic Tower of Hanoi rules.

The project demonstrates the use of **recursion, graphical programming, mouse interaction, dynamic difficulty, and double buffering** in C++.

---

## 📸 Overview

Tower of Hanoi is a classic mathematical puzzle consisting of three pegs and a number of disks of different sizes.

The objective is to move all disks from the source peg to the destination peg while following two rules:

1. Only **one disk** can be moved at a time.
2. A **larger disk cannot be placed on top of a smaller disk**.

This project turns the traditional puzzle into an interactive graphical game.

---

## ✨ Features

- 🎮 Interactive graphical gameplay
- 🖱️ Mouse-based disk movement
- 🗼 Three-peg Tower of Hanoi puzzle
- 🔄 Recursive Tower of Hanoi algorithm
- 🎚️ Dynamic difficulty based on the number of disks
- 🖼️ Graphical representation using `graphics.h`
- ⚡ Double buffering to reduce screen flickering
- 🏆 Win-state detection
- 🎨 Custom graphical game interface

---

## 🛠️ Technologies Used

| Technology           | Purpose                          |
| -------------------- | -------------------------------- |
| **C++**              | Core programming language        |
| **graphics.h**       | GUI and graphical rendering      |
| **Recursion**        | Tower of Hanoi solving algorithm |
| **Mouse Input**      | Interactive disk movement        |
| **Double Buffering** | Smooth graphical rendering       |

---

## 📂 Project Structure

```text
TOH/
│
├── toh1.cpp              # Main C++ source code
├── toh1.exe              # Windows executable
├── toh1.o                # Compiled object file
│
├── start.jpg             # Start/game screen asset
├── disk.jpg              # Disk graphics
├── no_disks.jpg          # Empty/no-disk state
├── peg_candel.jpg        # Peg graphics
├── peg_candel_fire.jpg   # Peg/game-state graphic
├── peg_candel_fire2.jpg  # Game-state graphic
├── peg_candel_fire3.jpg  # Game-state graphic
├── table.jpg             # Table/background graphic
├── you_won.jpg           # Winning screen
│
├── Makefile.win          # Windows build configuration
└── README.md
```

---

## 🧠 How Tower of Hanoi Works

The game is based on a recursive algorithm.

For `n` disks, the general approach is:

```text
Move n-1 disks from Source → Auxiliary
Move the largest disk from Source → Destination
Move n-1 disks from Auxiliary → Destination
```

The minimum number of moves required to solve the puzzle is:

```text
2ⁿ - 1
```

For example:

| Disks | Minimum Moves |
| ----: | ------------: |
|     1 |             1 |
|     2 |             3 |
|     3 |             7 |
|     4 |            15 |
|     5 |            31 |
|     6 |            63 |
|     7 |           127 |

As the number of disks increases, the difficulty grows exponentially.

---

## 🎮 Gameplay

The player interacts with the puzzle through the graphical interface.

### Basic Controls

- Select a disk using the mouse.
- Move the selected disk to another peg.
- A move is valid only when it follows the Tower of Hanoi rules.
- Continue moving disks until all disks are transferred to the destination peg.
- Successfully completing the puzzle displays the winning state.

---

## 🚀 Getting Started

### Prerequisites

Because this project uses `graphics.h`, you need a C++ environment that supports the graphics library.

A Windows-based setup compatible with the project's existing build configuration is recommended.

### Clone the Repository

```bash
git clone https://github.com/xeniumhs/toh.git
cd toh
```

### Build

If your environment is configured with the required graphics library and compiler, you can compile the source using your preferred C++ build setup.

For a MinGW-based environment, a command similar to the following may be used:

```bash
g++ toh1.cpp -o toh1.exe
```

> **Note:** `graphics.h` is not included in standard modern C++. Your compiler/environment must have a compatible implementation configured before building.

### Run

On Windows:

```bash
./toh1.exe
```

Or run the generated executable directly.

---

## 🧩 Core Concepts Demonstrated

This project was developed to demonstrate several fundamental programming concepts:

### Recursion

The Tower of Hanoi algorithm is implemented using recursive problem solving.

### Data Structures

The program manages disks and their movement between the three pegs.

### Event Handling

Mouse interactions are used to allow the player to interact with the graphical interface.

### Graphics Programming

The project uses `graphics.h` to render the game environment, pegs, disks, and different game states.

### Double Buffering

Double buffering is used to improve rendering quality and reduce visible flickering during graphical updates.

---

## 🎯 Learning Objectives

Through this project, we explored:

- Recursive algorithms
- Problem decomposition
- C++ programming
- GUI development
- Mouse event handling
- Basic game development
- Graphics rendering
- Algorithmic complexity
- User interaction
- Build and compilation workflows

---

## 👥 Project

This project was developed as a **group project** to demonstrate C++ programming, recursion, and graphical user interface development.

---

## 👥 Team Members

**Xenium Suwal** · **Rushal Manandhar** · **Kriti Koju** · **Malika Budhathoki**

## 📄 License

This project is intended primarily for educational purposes.

---

## ⭐ Acknowledgement

The project is based on the classic **Tower of Hanoi** mathematical puzzle and was implemented as an interactive graphical application in C++.

If you find the project useful or interesting, consider giving the repository a ⭐.
