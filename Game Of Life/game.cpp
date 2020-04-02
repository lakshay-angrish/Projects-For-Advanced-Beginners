#include "game.h"

#include<iostream>
#include<vector>

using namespace std;

void render(vector<vector<int> >& board) {
    char ch;
    for (int i = 0; i != board.size(); i++) {
        for (int j = 0; j != board[i].size(); j++) {
            ch = board[i][j] == 0 ? ' ' : '#';
            cout << ch;
        }
        cout << '\n';
    }
}

vector<vector<int> > random_state(int width, int height) {
    vector<vector<int> > board(height, vector<int>(width, 0));
    double val = 0;
    for (int i = 0; i != board.size(); i++) {
        for (int j = 0; j != board[i].size(); j++) {
           val = ((double) rand() / (RAND_MAX));
           board[i][j] = val > 0.5 ? 1 : 0;
        }
    }

    return board;
}

void next_cell_state(int state, vector<vector<int> >& new_board, int i, int j, int neighbors) {
    if (state == 0) {
        if (neighbors == 3) new_board[i][j] = 1;
        return;
    } else {
        if (neighbors > 3 || neighbors < 2) new_board[i][j] = 0;
    }
}

void corner_cases(vector<vector<int> >& board, vector<vector<int> >& new_board) {
    int i = 0, j = 0, neighbors;
    neighbors = board[i + 1][j] + board[i][j + 1] + board[i + 1][j + 1];
    next_cell_state(board[i][j], new_board, i, j, neighbors);

    j = board[0].size() - 1;
    neighbors = board[i + 1][j] + board[i][j - 1] + board[i + 1][j - 1];
    next_cell_state(board[i][j], new_board, i, j, neighbors);

    i = board.size() - 1;
    neighbors = board[i - 1][j] + board[i][j - 1] + board[i - 1][j - 1];
    next_cell_state(board[i][j], new_board, i, j, neighbors);

    j = 0;
    neighbors = board[i - 1][j] + board[i][j + 1] + board[i - 1][j + 1];
    next_cell_state(board[i][j], new_board, i, j, neighbors);
}

void edge_cases(vector<vector<int> >& board, vector<vector<int> >& new_board) {
    int neighbors, bottom = board.size() - 1, right = board[0].size() - 1;
    //going horizontal
    for (int j = 1; j != board[0].size() - 1; j++) {
        //cells in the top row
        neighbors = board[0][j - 1] + board[0][j + 1] + board[1][j] + board[1][j - 1] + board[1][j + 1];
        next_cell_state(board[0][j], new_board, 0, j, neighbors);

        //cells in the bottom row
        neighbors = board[bottom][j - 1] + board[bottom][j + 1] + board[bottom - 1][j] + board[bottom - 1][j - 1] + board[bottom - 1][j + 1];
        next_cell_state(board[bottom][j], new_board, bottom, j, neighbors);
    }

    //going vertical
    for (int j = 1; j != board.size() - 1; j++) {
        //cells in the leftmost column
        neighbors = board[j - 1][0] + board[j + 1][0] + board[j - 1][1] + board[j][1] + board[j + 1][1];
        next_cell_state(board[j][0], new_board, j, 0, neighbors);

        //cells in the rightmost column
        neighbors = board[j - 1][right] + board[j + 1][right] + board[j - 1][right - 1] + board[j][right - 1] + board[j + 1][right - 1];
        next_cell_state(board[j][right], new_board, j, right, neighbors);
    }
}

void next_state(vector<vector<int> >& board) {
    vector<vector<int> > new_board = board;

    corner_cases(board, new_board);
    edge_cases(board, new_board);

    //rest of the cells
    int neighbors;
    for (int i = 1; i != board.size() - 1; i++) {
        for (int j = 1; j != board[i].size() - 1; j++) {
           neighbors = board[i - 1][j] + board[i + 1][j] + board[i][j - 1] + board[i][j + 1] + board[i - 1][j - 1] + board[i + 1][j + 1] + board[i + 1][j - 1] + board[i - 1][j + 1];
           next_cell_state(board[i][j], new_board, i, j, neighbors);
        }
    }

    board = new_board;
}
