#include "game.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> board = new_board();
    char p[2] = {'X', 'O'};

    render(board);

    int i;
    char winner;
    for (i = 0; i != 9; i++) {
        board = make_move(get_move(board), board, p[i % 2]);
        render(board);
        winner = check_winner(board);
        if (winner == 'X') {
            cout << string(60, ' ') << "Player 1 Wins!\n";
            break;
        }
        if (winner == 'O') {
            cout << string(60, ' ') << "Player 2 Wins!\n";
            break;
        }
    }

    if (i == 9) {
        cout << string(60, ' ') << "     DRAW\n";
    }

    return 0;
}