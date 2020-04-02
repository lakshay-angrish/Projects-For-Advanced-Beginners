#include "game.h"

#include<iostream>
#include<vector>
#include<string>
#include<unistd.h>

using namespace std;

int main() {
    int width, height;
    cin >> width >> height;
    vector<vector<int> > board = random_state(width, height);

    for (int i = 0; i != 1000000; i++) {
        render(board);
        usleep(50000);
        cout << string(100, '\n');
        next_state(board);
    }

    return 0;
}