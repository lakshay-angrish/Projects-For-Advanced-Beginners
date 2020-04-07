#include "ai.h"
#include "game.h"

#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <fstream>

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

pair<int, int> find_winning_move_ai(vector<string>& board, char player) {
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

pair<int, int> find_winning_and_losing_move_ai(vector<string>& board, char player) {
    char opponent = player == 'X' ? 'O' : 'X';

    //WINNING MOVE SEARCH
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

    //LOSING MOVE SEARCH
    return find_winning_move_ai(board, opponent);
}

vector<pair<int, int> > legal_moves(vector<string>& board) {
    vector<pair<int, int> > moves;

    for (int i = 0; i != 3; i++) {
        for (int j = 0; j != 3; j++) {
            if (board[i][j] == ' ') {
                moves.push_back(pair<int, int>(i + 1, j + 1));
            }
        }
    }

    return moves;
}

int minimax_score(vector<string>& board, char player) {
    string key = board[0] + board[1] + board[2];
    if (cache.count(key) != 0)  return cache[key];

    if (check_winner(board) == 'X')         return 10;
    else if (check_winner(board) == 'O')    return -10;
    else if (is_draw(board))                return 0;

    vector<int> scores;
    vector<pair<int, int> > moves = legal_moves(board);
    int score;

    for (auto move: moves) {
        vector<string> new_board = make_move(move, board, player);
        score = minimax_score(new_board, get_opponent(player));
        scores.push_back(score);
    }

    if (player == 'X')  cache.insert(pair<string, int>(key, *max_element(scores.begin(), scores.end())));
    else                cache.insert(pair<string, int>(key, *min_element(scores.begin(), scores.end())));

    return cache[key];
}

pair<int, int> minimax_ai(vector<string>& board, char player) {
    vector<pair<int, int> > moves = legal_moves(board);
    vector<int> scores;
    int score;

    for (auto move: moves) {
        vector<string> new_board = make_move(move, board, player);
        score = minimax_score(new_board, get_opponent(player));
        if ((player == 'X' && score == 10) || (player == 'O' && score == -10))  return move;
        scores.push_back(score);
    }

    int low_idx = 0, high_idx = 0, high_score = scores[0], low_score = scores[0];
    for (int i = 0; i != scores.size(); i++) {
        if (scores[i] > high_score) {
            high_score = scores[i];
            high_idx = i;
        }
        if (scores[i] < low_score) {
            low_score = scores[i];
            low_idx = i;
        }
    }

    if (player == 'X')  return moves[high_idx];
    else                return moves[low_idx];
}

void load_cache() {
    fstream file("data.csv", ios::in);
    string line, key;
    int x, y, i;

    while(getline(file, line)) {
        key = "";
        for (i = 0; line[i] != ','; i++) {
            key += line[i];
        }
        i++;
        x = line[i++] - '0';
        i++;
        y = line[i] - '0';

        coords.insert(pair<string, pair<int, int> >(key, pair<int, int>(x, y)));
    }
}

pair<int, int> minimax_ai_with_cache(vector<string>& board, char player) {
    string key = board[0] + board[1] + board[2];
    return coords[key];
}