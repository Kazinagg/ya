#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>

using namespace std;

bool checkWin(const map<int, map<int, char>>& board, int r, int c, char player) {
    int directions[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };
    for (auto dir : directions) {
        int inLine = 1;
        for (int step = 1; step <= 4; ++step) {
            int dr = r + step * dir[0];
            int dc = c + step * dir[1];
            if (board.find(dr) == board.end() || board.at(dr).find(dc) == board.at(dr).end() || board.at(dr).at(dc) != player) break;
            inLine++;
        }
        for (int step = 1; step <= 4; ++step) {
            int dr = r - step * dir[0];
            int dc = c - step * dir[1];
            if (board.find(dr) == board.end() || board.at(dr).find(dc) == board.at(dr).end() || board.at(dr).at(dc) != player) break;
            inLine++;
        }
        if (inLine >= 5) return true;
    }
    return false;
}

int main() {
    int n, r, c;
    cin >> n;
    map<int, map<int, char>> board;
    char players[2] = { 'X', 'O' };
    bool win = false;
    string result = "Draw";
    for (int i = 0; i < n; i++) {
        cin >> r >> c;
        char player = players[i % 2];
        board[r][c] = player;
        if (i >= 4 && checkWin(board, r, c, player)) {
            win = true;
            result = (player == 'X') ? "First" : "Second";
            if (i < n - 1) {
                result = "Inattention";
                break;
            }
        }
    }
    cout << result << endl;
    return 0;
}
