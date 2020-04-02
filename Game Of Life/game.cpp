#include<iostream>
#include<vector>

using namespace std;

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

int main() {
    int width, height;
    cin >> width >> height;
    vector<vector<int> > board = random_state(width, height);

    for (int i = 0; i != board.size(); i++) {
        for (int j = 0; j != board[i].size(); j++) {
            cout << board[i][j] << '\t';
        }
        cout << '\n';
    }

    return 0;
}