#include "game.h"
    #ifdef AI
        #include "ai.h"
    #endif

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

        #ifndef AI
            move = get_move(board);
        #endif

        #ifdef AI
            if (i % 2 == 0)  move = get_move(board);
            else        move = find_winning_and_losing_move_ai(board, p[1]);
        #endif

        board = make_move(move, board, p[i % 2]);

        #ifdef AI
            if (i % 2 != 0) render(board);
        #endif

        #ifndef AI
            render(board);
        #endif

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