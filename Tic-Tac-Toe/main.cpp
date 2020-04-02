#include "game.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> board = new_board();

    render(board);

    return 0;
}