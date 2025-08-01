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
    if (maze.empty() || maze[0].empty() || !maze[0][0]) return false;

    int rows = maze.size();
    int cols = maze[0].size();
    std::queue<Position> q;
    std::unordered_set<Position, Position::Hash> visited;
    std::unordered_map<Position, Position, Position::Hash> parent;

    Position start {0, 0};
    Position end {9, 9};

    q.push(start);
    visited.insert(start);

    //Represents the four cardinal directions:                    Up,           Down,           Left,          Right
    const std::vector<std::pair<int, int> > directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // BFS loop
    // Continue until the queue is empty or we reach the end very simple
    while (!q.empty()) {
        Position current = q.front(); q.pop();
        if (current == end) break;

        //try all four directions to find the next position
        // nr and nc are the new row and column indices
        for (auto [dr, dc] : directions) {
            int nr = current.row + dr;
            int nc = current.col + dc;
            Position neighbor = {nr,nc};

            // check if the neighbor is valid and not visited
            // nr and nc should be within bounds, maze[nr][nc] should be true (open), and neighbor should not be visited
            // if all these conditions are met, we can push the neighbor into the queue
            if (nr >= 0 && nr < rows && nc < cols && nc >= 0 && maze[nr][nc] && !visited.count(neighbor)) {
                q.push(neighbor);
                visited.insert(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    // if end is never reached return false
    if (!visited.count(end)) return false;

    // Reconstruct the path from end to start using the parent map
    for (Position at = end; at != start; at = parent[at]) {
        path.push_back(at);
    }
    path.push_back(start);

    // The path is constructed in reverse order, so we need to reverse it
    std::reverse(path.begin(), path.end());

    return true;
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
        {true, true, false, false, false, false, false, false, false, false},
        {false, true, false, false, false, false, false, false, false, false},
        {false, true, true, true, true, true, true, true, true, false},
        {false, false, false, false, false, false, false, false, true, false},
        {false, false, false, false, false, false, false, false, true, false},
        {false, false, false, false, false, false, false, false, true, false},
        {false, false, false, false, false, false, false, false, true, false},
        {false, false, false, false, false, false, false, false, true, false},
        {false, false, false, false, false, false, false, false, true, false},
        {false, false, false, false, false, false, false, false, true, true}
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