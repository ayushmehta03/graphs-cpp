#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int delRow[], int delCol[]) {
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < 4; i++) {
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
            !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
            dfs(nRow, nCol, grid, vis, delRow, delCol);
        }
    }
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    // First and last row
    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1 && !vis[0][j]) {
            dfs(0, j, grid, vis, delRow, delCol);
        }
        if (grid[n - 1][j] == 1 && !vis[n - 1][j]) {
            dfs(n - 1, j, grid, vis, delRow, delCol);
        }
    }

    // First and last column
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1 && !vis[i][0]) {
            dfs(i, 0, grid, vis, delRow, delCol);
        }
        if (grid[i][m - 1] == 1 && !vis[i][m - 1]) {
            dfs(i, m - 1, grid, vis, delRow, delCol);
        }
    }

    // Count enclaves
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
