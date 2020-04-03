#include "game.h"
#include "ai.h"

#include <iostream>
#include <vector>
#include <string>

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
    pair<int, int> move_made = finding_moves_ai(board, 'X');

    return expected_move == move_made;
}

bool test6() {
    vector<string> board = new_board();
    board[0][0] = 'X';
    board[0][2] = 'X';

    pair<int, int> expected_move(1, 2);
    pair<int, int> move_made = finding_moves_ai(board, 'X');

    return expected_move == move_made;
}

bool test7() {
    vector<string> board = new_board();
    board[0][2] = 'X';
    board[1][2] = 'X';

    pair<int, int> expected_move(3, 3);
    pair<int, int> move_made = finding_moves_ai(board, 'X');

    return expected_move == move_made;
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
        if (suite1[i]() == 'X') {
            cout << "PASSED " << ti++ + 1 << '\n';
        } else {
            cout << "FAILED " << ti++ + 1 << '\n';
        }
    }

    tests2 suite2[] = {
        test5,
        test6,
        test7
    };

    for (int i = 0; i != 3; i++) {
        if (suite2[i]()) {
            cout << "PASSED " << ti++ + 1 << '\n';
        } else {
            cout << "FAILED " << ti++ + 1 << '\n';
        }
    }


    // if (expected_move == move_made) {
    //     cout << "PASSED 5\n";
    // } else {
    //     cout << "FAILED 5\n";
    //     cout << "Returned = " << move_made.first << '\t' << move_made.second << '\n';
    //     cout << "Expected = " << expected_move.first << '\t' << expected_move.second << '\n';
    // }

    return 0;
}