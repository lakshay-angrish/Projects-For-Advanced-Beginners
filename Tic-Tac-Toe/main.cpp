#include "game.h"
#include "ai.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//string super_tab(60, ' ');

int main() {
    vector<string> board = new_board();
    char p[2] = {'X', 'O'}, mode;

    cout << super_tab << "1. P v/s P\n";
    cout << super_tab << "2. P v/s AI\n";
    cout << super_tab << "Enter choice = ";
    cin >> mode;

    while (mode != '1' && mode != '2') {
        cout << super_tab << "Invalid Choice!\n";
        cout << super_tab << "Enter Again = ";
        cin >> mode;
    }

    render(board);

    int i;
    char winner;
    pair<int, int> move;
    for (i = 0; i != 9; i++) {
        if (mode == '1') {
            move = get_move(board);
        } else {
            if (i % 2 == 0)  move = get_move(board);
            else        move = find_winning_and_losing_move_ai(board, p[1]);
        }

        board = make_move(move, board, p[i % 2]);

        if (mode == '2' && i % 2 == 0);
        else    render(board);

        winner = check_winner(board);
        if (winner == 'X') {
            cout << super_tab << "Player 1 Wins!\n";
            break;
        }
        if (winner == 'O') {
            cout << super_tab << "Player 2 Wins!\n";
            break;
        }
    }

    if (i == 9) {
        render(board);
        cout << super_tab << "     DRAW\n";
    }

    return 0;
}