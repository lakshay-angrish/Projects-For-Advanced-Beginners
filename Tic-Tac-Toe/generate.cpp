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
    if (x <= o) return 'X';
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

fstream file("data.csv", ios::out | ios::trunc);
map<string, int> keys;

void gen(vector<string>& board, char player) {
    vector<pair<int, int> > moves = legal_moves(board);
    vector<string> new_board;
    pair<int, int> perfect;
    string key;

    if (!is_full(board) && check_winner(board) == ' ') {
        for (auto move: moves) {
            new_board = make_move(move, board, player);
            key = new_board[0] + new_board[1] + new_board[2];
            if (!is_full(new_board) && keys.count(key) == 0) {
                perfect = minimax_ai(new_board, get_opponent(player));
                file << key << "," << perfect.first << "," << perfect.second << '\n';
                keys.insert(pair<string, int>(key, 1));
                gen(new_board, get_opponent(player));
            }
        }
    }
}

int main() {
    vector<string> board = new_board();
    // char ch[3] = {' ', 'X', 'O'};
    // string key;
    // fstream file("data.csv", ios::out | ios::trunc);

    // for (int i = 0; i != 3; i++) {
    //     for (int j = 0; j != 3; j++) {
    //         for (int k = 0; k != 3; k++) {
    //             for (int l = 0; l != 3; l++) {
    //                 for (int m = 0; m != 3; m++) {
    //                     for (int n = 0; n != 3; n++) {
    //                         for (int o = 0; o != 3; o++) {
    //                             for (int p = 0; p != 3; p++) {
    //                                 for (int q = 0; q != 3; q++) {
    //                                     key = "";
    //                                     key += ch[i];
    //                                     key += ch[j];
    //                                     key += ch[k];
    //                                     key += ch[l];
    //                                     key += ch[m];
    //                                     key += ch[n];
    //                                     key += ch[o];
    //                                     key += ch[p];
    //                                     key += ch[q];
    //                                     board[0][0] = ch[i];
    //                                     board[0][1] = ch[j];
    //                                     board[0][2] = ch[k];
    //                                     board[1][0] = ch[l];
    //                                     board[1][1] = ch[m];
    //                                     board[1][2] = ch[n];
    //                                     board[2][0] = ch[o];
    //                                     board[2][1] = ch[p];
    //                                     board[2][2] = ch[q];
    //                                     if (!is_full(board) && check_winner(board) == ' ') {
    //                                         pair<int, int> move = minimax_ai(board, which_move(board));
    //                                         file << key << "," << move.first << "," << move.second << '\n';
    //                                     }
    //                                 }
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    file << "         ,1,1\n";
    gen(board, 'X');
    file.close();

    return 0;
}