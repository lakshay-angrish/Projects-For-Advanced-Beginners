#include "ai.h"
#include "game.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

char which_move(vector<string>& board) {
    int x = 0, o = 0;
    for (int i = 0; i != 3; i++) {
        for (int j = 0; j != 3; j++) {
            if (board[i][j] == 'X') x++;
            if (board[i][j] == 'O') o++;
        }
    }
    if (x == o) return 'X';
    return 'O';
}

bool is_full(vector<string>& board) {
    for (int i = 0; i != 3; i++) {
        for (int j = 0; j != 3; j++) {
            if (board[i][j] == ' ') return false;;
        }
    }

    return true;
}

int main() {
    vector<string> board = new_board();
    char ch[3] = {' ', 'X', 'O'};
    string key;
    fstream file("data.csv", ios::out | ios::trunc);

    for (int i = 0; i != 3; i++) {
        for (int j = 0; j != 3; j++) {
            for (int k = 0; k != 3; k++) {
                for (int l = 0; l != 3; l++) {
                    for (int m = 0; m != 3; m++) {
                        for (int n = 0; n != 3; n++) {
                            for (int o = 0; o != 3; o++) {
                                for (int p = 0; p != 3; p++) {
                                    for (int q = 0; q != 3; q++) {
                                        key = "";
                                        key += ch[i];
                                        key += ch[j];
                                        key += ch[k];
                                        key += ch[l];
                                        key += ch[m];
                                        key += ch[n];
                                        key += ch[o];
                                        key += ch[p];
                                        key += ch[q];
                                        board[0][0] = ch[i];
                                        board[0][1] = ch[j];
                                        board[0][2] = ch[k];
                                        board[1][0] = ch[l];
                                        board[1][1] = ch[m];
                                        board[1][2] = ch[n];
                                        board[2][0] = ch[o];
                                        board[2][1] = ch[p];
                                        board[2][2] = ch[q];
                                        if (!is_full(board) && check_winner(board) == ' ') {
                                            pair<int, int> move = minimax_ai(board, which_move(board));
                                            file << key << "," << move.first << "," << move.second << '\n';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    file.close();

    return 0;
}