#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &board, vector<vector<int>> &vis, int delRow[], int delCol[]) {
    vis[row][col] = 1;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < 4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
            !vis[nRow][nCol] && board[nRow][nCol] == 'O') {
            dfs(nRow, nCol, board, vis, delRow, delCol);
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };
    
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Traverse first and last row
    for (int j = 0; j < m; j++) {
        if (!vis[0][j] && board[0][j] == 'O') {
            dfs(0, j, board, vis, delRow, delCol);
        }
        if (!vis[n-1][j] && board[n-1][j] == 'O') {
            dfs(n-1, j, board, vis, delRow, delCol);
        }
    }

    // Traverse first and last column
    for (int i = 0; i < n; i++) {
        if (!vis[i][0] && board[i][0] == 'O') {
            dfs(i, 0, board, vis, delRow, delCol);
        }
        if (!vis[i][m-1] && board[i][m-1] == 'O') {
            dfs(i, m-1, board, vis, delRow, delCol);
        }
    }

    // Replace all unvisited 'O' with 'X'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'O' && !vis[i][j]) {
                board[i][j] = 'X';
            }
        }
    }

    for (auto row : board) {
        for (auto ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }
}
