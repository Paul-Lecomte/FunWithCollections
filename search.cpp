// search.cpp
#include <iostream>
#include "map.h"
#include "set.h"
#include "vector.h"
#include "strlib.h"
#include "filelib.h"
#include "tokenscanner.h"
#include "testing/SimpleTest.h"
using namespace std;

Map<string, Set<int>> buildIndex(Vector<string>& files) {
    Map<string, Set<int>> index;
    // Your implementation goes here
    return index;
}

Set<int> findQueryMatches(Map<string, Set<int>>& index, string query) {
    Set<int> result;
    // Your implementation goes here
    return result;
}

/* * * * * * Test Cases Below This Point * * * * * */

STUDENT_TEST("Basic inverted index build test") {
    Vector<string> files = {
        "The cat in the hat",
        "The dog chased the cat",
        "A cat and a dog"
    };
    Map<string, Set<int>> index = buildIndex(files);

    EXPECT(index.containsKey("cat"));
    EXPECT_EQUAL(index["cat"].size(), 3);
}

/* Entry point for testing */
int main() {
    if (runSimpleTests(0)) {
        return 0;
    }
    return 0;
}
