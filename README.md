# Rock Paper Scissors (C++)
A modular, clean-code console implementation of the classic Rock-Paper-Scissors game, built with advanced structural C++ concepts.

## 🌟 Features
* **Player vs Computer:** Interactive CLI gameplay with randomized AI choice logic.
* **Visual & Audio Feedback:** Dynamic console background colors (Green/Red/Yellow) and audio alerts based on round outcomes.
* **Detailed Match Statistics:** End-of-game dashboard tracking total rounds, wins, losses, and draws.
* **Replay Mechanics:** Built-in game loop allowing players to restart matches seamlessly.

## 🧠 Concepts & Architecture Practiced
* **Data Encapsulation:** Grouped round details and game statistics into custom `struct` models (`stRoundInfo`, `stGameResults`).
* **Strong Typing:** Applied `enum` types for safe game options and state management.
* **Efficient Mapping:** Replaced complex conditional checks with `Array Lookup` pattern for fast string transformations.
* **Modular Design:** Built using a **Bottom-Up** architecture with single-responsibility helper functions.
* **Console UI/UX:** Managed screen clearing (`cls`) and visual background formatting.

## 🛠️ Technologies
* **Language:** C++
* **Environment:** Windows Console CLI

> ⚠️ **Platform Note:** This project relies on Windows-specific console commands (`system("cls")` and `system("color ...")`) for screen clearing and color/audio feedback. It will compile and run on other platforms, but the visual color effects and screen clearing will not work outside of Windows.

## 🚀 How to Build & Run
1. Make sure you have a C++ compiler installed (e.g., **MinGW / g++**, or **Visual Studio**).
2. Compile the source file:
   ```bash
   g++ main.cpp -o game.exe
   ```
3. Run the generated executable:
   ```bash
   game.exe
   ```

## 🎯 Purpose
Created as part of my C++ learning journey to transition from basic procedural programming into writing clean, maintainable, and professionally structured code.
