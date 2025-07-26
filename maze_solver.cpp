#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

// Step 1: Position struct to hold a cell coordinate
struct Position {
    int row, col;

    bool operator==(const Position& other) const {
        return row == other.row && col == other.col;
    }
    bool operator!=(const Position& other) const {
        return !(*this == other);
    }

    struct Hash {
        size_t operator()(const Position& pos) const {
            return std::hash<int>()(pos.row) ^ (std::hash<int>()(pos.col) << 1);
        }
    };
};

// Maze type: 2D grid of booleans (true=open, false=wall)
using Maze = std::vector<std::vector<bool>>;

// Function to find path - to be implemented
bool findPath(const Maze& maze, std::vector<Position>& path) {
    // TODO: implement BFS here
    return false;
}

// Helper to print the path
void printPath(const std::vector<Position>& path) {
    for (const auto& pos : path) {
        std::cout << "(" << pos.row << ", " << pos.col << ") ";
    }
    std::cout << "\n";
}

int main() {
    Maze maze = {
        {true, true, false},
        {false, true, false},
        {false, true, true}
    };

    std::vector<Position> path;
    if (findPath(maze, path)) {
        std::cout << "Path found:\n";
        printPath(path);
    } else {
        std::cout << "No path found.\n";
    }
    return 0;
}