#include "game.h"
#include "ai.h"

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
    pair<int, int> move;
    for (i = 0; i != 9; i++) {
        if (i % 2 == 0)  move = get_move(board);
        else        move = finding_moves_ai(board, p[1]);

        board = make_move(move, board, p[i % 2]);
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