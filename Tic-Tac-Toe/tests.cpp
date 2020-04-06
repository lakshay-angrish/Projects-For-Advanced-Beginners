#include "game.h"
#include "ai.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef char (*tests1) (void);
typedef bool (*tests2) (void);

char test1() {
    vector<string> board = new_board();
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'X';

    return check_winner(board);
}

char test2() {
    vector<string> board = new_board();
    board[0][0] = 'X';
    board[1][1] = 'X';
    board[2][2] = 'X';

    return check_winner(board);
}

char test3() {
    vector<string> board = new_board();
    board[0][2] = 'X';
    board[1][1] = 'X';
    board[2][0] = 'X';

    return check_winner(board);
}

char test4() {
    vector<string> board = new_board();
    board[0][0] = 'X';
    board[1][0] = 'X';
    board[2][0] = 'X';

    return check_winner(board);
}

bool test5() {
    vector<string> board = new_board();
    board[0][0] = 'X';
    board[1][1] = 'X';

    pair<int, int> expected_move(3, 3);
    pair<int, int> move_made = find_winning_move_ai(board, 'X');

    return expected_move == move_made;
}

bool test6() {
    vector<string> board = new_board();
    board[0][0] = 'X';
    board[0][2] = 'X';

    pair<int, int> expected_move(1, 2);
    pair<int, int> move_made = find_winning_move_ai(board, 'X');

    return expected_move == move_made;
}

bool test7() {
    vector<string> board = new_board();
    board[0][2] = 'X';
    board[1][2] = 'X';

    pair<int, int> expected_move(3, 3);
    pair<int, int> move_made = find_winning_move_ai(board, 'X');

    return expected_move == move_made;
}

bool test8() {
    vector<string> board = new_board();
    board[0][2] = 'X';
    board[1][2] = 'X';

    pair<int, int> expected_move(3, 3);
    pair<int, int> move_made = find_winning_and_losing_move_ai(board, 'O');

    return expected_move == move_made;
}

bool test9() {
    vector<string> board = new_board();
    board[0][0] = 'X';
    board[1][0] = 'X';
    board[0][1] = 'O';
    board[1][1] = 'O';

    pair<int, int> expected_move(3, 2);
    pair<int, int> move_made = find_winning_and_losing_move_ai(board, 'O');

    return expected_move == move_made;
}

bool test10() {
    vector<string> board = new_board();
    board[0][0] = 'X';
    board[1][1] = 'X';
    board[0][1] = 'O';
    board[2][0] = 'O';

    pair<int, int> expected_move(3, 3);
    pair<int, int> move_made = find_winning_and_losing_move_ai(board, 'O');

    return expected_move == move_made;
}

bool test11() {
    vector<string> board = new_board();
    board[1][1] = 'X';
    board[2][0] = 'X';
    board[2][2] = 'O';

    pair<int, int> expected_move(1, 3);
    pair<int, int> move_made = find_winning_and_losing_move_ai(board, 'O');

    return expected_move == move_made;
}

int test12(string ai1, string ai2, int iterations) {
    pair<int, int> (*AI1)(vector<string>&, char);
    pair<int, int> (*AI2)(vector<string>&, char);
    char p[2] = {'X', 'O'}, winner;
    int score1 = 0, score2 = 0, i;

    if (ai1 == "random_ai")                               AI1 = random_ai;
    else if (ai1 == "find_winning_move_ai")               AI1 = find_winning_move_ai;
    else if (ai1 == "find_winning_and_losing_move_ai")    AI1 = find_winning_and_losing_move_ai;
    else if (ai1 == "minimax_ai")                         AI1 = minimax_ai;

    if (ai2 == "random_ai")                               AI2 = random_ai;
    else if (ai2 == "find_winning_move_ai")               AI2 = find_winning_move_ai;
    else if (ai2 == "find_winning_and_losing_move_ai")    AI2 = find_winning_and_losing_move_ai;
    else if (ai2 == "minimax_ai")                         AI2 = minimax_ai;

    for (int j = 0; j != iterations; j++) {
        vector<string> board = new_board();
        pair<int, int> move;

        for (i = 0; i != 9; i++) {
            move = i % 2 == 0 ? AI1(board, 'X') : AI2(board, 'O');
            board = make_move(move, board, p[i % 2]);

            winner = check_winner(board);
            if (winner == 'X') {
                score1++;
                break;
            }
            if (winner == 'O') {
                score2++;
                break;
            }
        }
    }

    return ceil(double(score1 * 100) / (iterations));
}

int main() {
    int ti = 0;

    tests1 suite1[] = {
        test1,
        test2,
        test3,
        test4
    };

    for (int i = 0; i != 4; i++) {
        cout << "TEST " << ++ti << " ==> ";
        if (suite1[i]() == 'X') {
            cout << "PASSED\n";
        } else {
            cout << "FAILED\n";
        }
    }

    tests2 suite2[] = {
        test5,
        test6,
        test7,
        test8,
        test9,
        test10,
        test11
    };

    for (int i = 0; i != 7; i++) {
        cout << "TEST " << ++ti << " ==> ";
        if (suite2[i]()) {
            cout << "PASSED\n";
        } else {
            cout << "FAILED\n";
        }
    }

    string ais[] = {
        "random_ai",
        "find_winning_move_ai",
        "find_winning_and_losing_move_ai",
        "minimax_ai"
    };

    int score1;
    string out;
    for (int i = 0; i != 4; i++) {
        for (int j = i + 1; j < 4 && j != i; j++) {
            cout << "TEST " << ++ti << " ==> ";
            score1 = test12(ais[i], ais[j], 10000);
            out = ais[i] + " v/s " + ais[j] + " ";
            out += string(57 - out.size(), ' ');
            cout << out << ":" << ais[i] << " won " << score1 << "% of games\n";
        }
    }

    return 0;
}