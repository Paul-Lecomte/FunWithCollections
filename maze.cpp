// maze.cpp
#include <iostream>
#include "grid.h"
#include "set.h"
#include "vector.h"
#include "queue.h"
#include "stack.h"
#include "testing/SimpleTest.h"
using namespace std;

bool findPath(Grid<bool>& maze, Vector<GridLocation>& path) {
    // Your implementation goes here
    return false;
}

/* * * * * * Test Cases Below This Point * * * * * */

STUDENT_TEST("Test on simple 3x3 maze") {
    Grid<bool> maze = {
        { true,  true, false },
        { false, true, false },
        { false, true, true  }
    };
    Vector<GridLocation> path;
    EXPECT(findPath(maze, path));
}

/* Entry point for testing */
int main() {
    if (runSimpleTests(0)) {
        return 0;
    }
    return 0;
}