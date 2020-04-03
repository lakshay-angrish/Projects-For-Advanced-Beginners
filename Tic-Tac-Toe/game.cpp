#include "game.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

string super_tab(60, ' ');

vector<string> new_board() {
    return vector<string>(3, string(3, ' '));
}

void render(vector<string>& board) {

    cout << super_tab << "    1     2     3   \n";
    cout << super_tab << " ===================\n";
    for (int i = 0; i != board.size(); i++) {
        cout << super_tab << " |     |     |     |\n";
        cout << super_tab << i + 1 << "|  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  |\n";
        cout << super_tab << " |     |     |     |\n";
        cout << super_tab << " ===================\n";
    }
}

pair<int, int> get_move(vector<string>& board) {
    int x, y;
    cout << super_tab << "Enter coordinates(x y) = ";
    cin >> x >> y;
    while (x < 1 || x > 3 || y < 1 || y > 3 || board[x - 1][y - 1] != ' ') {
        cout << super_tab << "ERROR: Invalid move\n";
        cout << super_tab << "Enter (x y) = ";
        cin >> x >> y;
    }
    return pair<int, int>(x, y);
}

vector<string> make_move(pair<int, int> coords, vector<string>& board, char player) {
    vector<string> new_board = board;
    new_board[coords.first - 1][coords.second - 1] = player;

    return new_board;
}