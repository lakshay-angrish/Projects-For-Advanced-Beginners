#include "game.h"
    #if AI || AI2
        #include "ai.h"
    #endif

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    vector<string> board = new_board();
    char p[2] = {'X', 'O'};

    #ifdef AI2
        pair<int, int> (*ai1)(vector<string>&, char);
        pair<int, int> (*ai2)(vector<string>&, char);

        if (argc > 1) {
            if (argc == 3) {
                string s = string(argv[1]);
                if (s == "random_ai")                               ai1 = random_ai;
                else if (s == "find_winning_move_ai")               ai1 = find_winning_move_ai;
                else if (s == "find_winning_and_losing_move_ai")    ai1 = find_winning_and_losing_move_ai;
                else {
                    cout << super_tab << "Invalid AI entered!\n";
                    return 1;
                }

                s = string(argv[2]);
                if (s == "random_ai")                               ai2 = random_ai;
                else if (s == "find_winning_move_ai")               ai2 = find_winning_move_ai;
                else if (s == "find_winning_and_losing_move_ai")    ai2 = find_winning_and_losing_move_ai;
                else {
                    cout << super_tab << "Invalid AI entered!\n";
                    return 1;
                }

            } else {
                cout << super_tab << "Must supply two AIs!\n";
                return 1;
            }
        } else {
            cout << super_tab << "Must supply two AIs!\n";
            return 1;
        }
    #endif

    render(board);

    int i;
    char winner;
    pair<int, int> move;
    for (i = 0; i != 9; i++) {

        #if !AI && !AI2
            move = get_move(board);
        #endif

        #ifdef AI
            if (i % 2 == 0)  move = get_move(board);
            else        move = find_winning_and_losing_move_ai(board, p[1]);
        #endif

        #ifdef AI2
            if (i % 2 == 0)  move = ai1(board, p[0]);
            else        move = ai2(board, p[1]);
        #endif

        board = make_move(move, board, p[i % 2]);

        #ifdef AI
            if (i % 2 != 0) render(board);
        #endif

        #if !AI && !AI2
            render(board);
        #endif

        winner = check_winner(board);
        #ifdef AI2
            if(winner != ' ')    render(board);
        #endif
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