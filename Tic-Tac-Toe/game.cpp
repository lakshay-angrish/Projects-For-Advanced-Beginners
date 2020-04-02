#include "game.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> new_board() {
    return vector<string>(3, string(3, ' '));
}

void render(vector<string>& board) {
    string super_tab(60, ' ');

    cout << super_tab << "===================\n";
    for (int i = 0; i != board.size(); i++) {
        cout << super_tab << "|     |     |     |\n";
        cout << super_tab << "|  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  |\n";
        cout << super_tab << "|     |     |     |\n";
        cout << super_tab << "===================\n";
    }
}