# CS106B Assignment 2 – Maze Pathfinding with STL

[![C++](https://img.shields.io/badge/language-C%2B%2B17-blue.svg)](https://en.cppreference.com/w/cpp/17)  
[![Course](https://img.shields.io/badge/course-CS106B%20Stanford-red)](https://web.stanford.edu/class/cs106b/)

## Assignment Overview

This assignment focuses on applying **graph traversal algorithms** using C++ Standard Library data structures to solve a classic problem: **finding a path through a maze**.

You will:

- Implement the **Breadth-First Search (BFS)** algorithm to find the shortest path in a grid maze.
- Use STL containers such as `vector`, `queue`, `unordered_set`, and `unordered_map`.
- Practice working with **custom data types** and hashing (`struct Position`).
- Understand how to reconstruct a path once the goal is reached.

## Starter Code

You have been provided with a starter program that:

- Defines a `Position` struct representing coordinates in the maze.
- Contains a sample maze represented as a 2D `vector<vector<bool>>`.
- Has a stub for the function `findPath()` which you will implement using BFS.
- Includes helper functions for path printing and a `main()` function with a test maze.

---

## Your Implementation Tasks

### 1. Define Position and Maze

- `Position` holds `(row, col)` coordinates.
- Implement equality (`==`) and inequality (`!=`) operators for `Position`.
- Provide a hash function for `Position` so it can be used in hash-based STL containers.

### 2. Implement BFS in `findPath`

- Use a `queue` to manage the frontier of positions to explore.
- Use an `unordered_set` to keep track of visited positions to avoid revisiting.
- Use an `unordered_map` to store parent relationships, enabling path reconstruction.
- Explore neighbors in the four cardinal directions (up, down, left, right), ensuring moves stay inside the maze boundaries and only move through open cells (`true`).

### 3. Path Reconstruction

- Once the target cell is found (bottom-right corner), reconstruct the path by backtracking through the parent map.
- Store the path in the output parameter `std::vector<Position>& path`, ordered from start to finish.

### 4. Testing

- Run the provided `main()` function.
- Test on the given maze and additional mazes you create.
- Confirm the program prints the correct path or indicates no path found.

---

## Compilation Instructions

Use the following command to compile your program:

```bash
g++ maze_solver.cpp -std=c++17 -o maze_solver
```

Run the program with:

```bash
./maze_solver
```

---

## Tips and Reminders

- Focus on correct usage of STL containers, especially `unordered_map` and `unordered_set` with custom hash functions.
- Make sure `operator==` and the hash function for `Position` are consistent.
- Think carefully about edge cases: empty mazes, fully blocked paths, etc.
- Use debug prints to trace your BFS process if stuck.
- Reversing the path vector after backtracking will give the path from start to goal.

---

For any questions or help, feel free to ask!

Good luck with your implementation — this is a great exercise for mastering STL and graph algorithms!
