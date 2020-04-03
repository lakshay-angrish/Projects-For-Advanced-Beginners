#include "game.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef char (*tests) (void);

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

int main() {
    tests suite[] = {
        test1,
        test2,
        test3,
        test4
    };

    for (int i = 0; i != 4; i++) {
        if (suite[i]() == 'X') {
            cout << "PASSED " << i + 1 << '\n';
        } else {
            cout << "FAILED " << i + 1 << '\n';
        }
    }

    return 0;
}