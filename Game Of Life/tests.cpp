#include "game.h"

#include <vector>
#include <iostream>

using namespace std;

void test1() {
    vector<vector<int> > init_state;
    init_state.push_back(vector<int>{0, 0, 0});
    init_state.push_back(vector<int>{0, 0, 0});
    init_state.push_back(vector<int>{0, 0, 0});

    vector<vector<int> > expected_next_state;
    expected_next_state.push_back(vector<int>{0, 0, 0});
    expected_next_state.push_back(vector<int>{0, 0, 0});
    expected_next_state.push_back(vector<int>{0, 0, 0});

    next_state(init_state);

    if (init_state == expected_next_state) {
        cout << "PASSED 1\n";
    } else {
        cout << "FAILED 1\n";
    }
}

void test2() {
    vector<vector<int> > init_state;
    init_state.push_back(vector<int>{0, 0, 1});
    init_state.push_back(vector<int>{0, 1, 1});
    init_state.push_back(vector<int>{0, 0, 0});

    vector<vector<int> > expected_next_state;
    expected_next_state.push_back(vector<int>{0, 1, 1});
    expected_next_state.push_back(vector<int>{0, 1, 1});
    expected_next_state.push_back(vector<int>{0, 0, 0});

    next_state(init_state);

    if (init_state == expected_next_state) {
        cout << "PASSED 2\n";
    } else {
        cout << "FAILED 2\n";
    }
}

int main() {
    test1();
    test2();

    return 0;
}