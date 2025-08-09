#include<iostream>
#include<queue>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>&grid,vector<vector<int>>&visited){
    int n=grid.size();
    int m=grid[0].size();
if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
    if(n==1 &&grid[0][0]==0) return 1;

    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0][0]=1;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        int distance=visited[r][c];

        int delRow[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int delCol[8] = {0, 0, -1, 1, -1, 1, -1, 1};
        if(r==n-1 && c==m-1) return distance;
        for(int i=0;i<8;i++){
         int nRow=r+delRow[i];
         int nCol=c+delCol[i];
         if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m&&!visited[nRow][nCol]&&grid[nRow][nCol]==0){
            visited[nRow][nCol]=distance+1;
            q.push({nRow,nCol});

         }

        }

    }
    return -1;
}


int main(){
    vector<vector<int>>grid= {{0,0,0},{1,1,0},{1,1,0}};
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    int ans=shortestPathBinaryMatrix(grid,visited);
    return ans;
    
}