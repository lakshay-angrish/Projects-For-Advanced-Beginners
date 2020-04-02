#include "game.h"

#include <iostream>
#include <vector>
#include <unistd.h>
#include <string>

using namespace std;

int main() {
    string path = "gun.txt";

    vector<vector<int> > board = load_state(path);

    while (true) {
        render(board);
        usleep(100000);
        cout << string(100, '\n');
        next_state(board);
    }

    return 0;
}