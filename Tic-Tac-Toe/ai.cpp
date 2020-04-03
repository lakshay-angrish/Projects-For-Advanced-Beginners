#include "ai.h"

#include <vector>
#include <string>
#include <random>

using namespace std;

random_device rd;
mt19937 eng(rd());
uniform_int_distribution<> numbers(0, 2);

pair<int, int> random_ai(vector<string>& board, char player) {
    int x = numbers(eng);
    int y = numbers(eng);

    while (board[x][y] != ' ') {
        x = numbers(eng);
        y = numbers(eng);
    }

    return pair<int, int>(x + 1, y + 1);
}

pair<int, int> finding_moves_ai(vector<string>& board, char player) {
    int count = 0;
    //check in columns
    for (int i = 0; i != 3; i++) {
        count = 0;
        if (board[0][i] == player)  count++;
        if (board[1][i] == player)  count++;
        if (board[2][i] == player)  count++;

        if (count == 2) {
            for (int k = 0; k != 3; k++) {
                if (board[k][i] == ' ') return pair<int, int>(k + 1, i + 1);
            }
        }
    }

    //check in columns
    for (int i = 0; i != 3; i++) {
        count = 0;
        if (board[i][0] == player)  count++;
        if (board[i][1] == player)  count++;
        if (board[i][2] == player)  count++;

        if (count == 2) {
            for (int k = 0; k != 3; k++) {
                if (board[i][k] == ' ') return pair<int, int>(i + 1, k + 1);
            }
        }
    }

    //check in diagonals
    int left_count = 0, right_count = 0;
    for (int i = 0; i != 3; i++) {
        if (board[i][i] == player)  left_count++;
        if (board[i][2 - i] == player)  right_count++;
    }
    if (left_count == 2) {
        for (int k = 0; k != 3; k++) {
            if (board[k][k] == ' ') return pair<int, int>(k + 1, k + 1);
        }
    }
    if (right_count == 2) {
        for (int k = 0; k != 3; k++) {
            if (board[k][2 - k] == ' ') return pair<int, int>(k + 1, 2 - k + 1);
        }
    }

    return random_ai(board, player);
}