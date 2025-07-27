#include <iostream>
#include<vector>
#include<queue>
using namespace std;


vector<vector<int>>updateMatrix(vector<vector<int>>&mat,int delCol[],int delRow[]){
    int n=mat.size();
    int m=mat[0].size();
    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                vis[i][j]=1;
                q.push({{i,j},0});
            }
        }
    }

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps=q.front().second;
        q.pop();
        dis[row][col]=steps;
        for(int i=0;i<4;i++){
            int nRow=row+delRow[i];
            int nCol=col+ delCol[i];
            if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m&&vis[nRow][nCol]==0){
                vis[nRow][nCol]=1;
                q.push({{nRow,nCol},steps+1});
            }
        }
    }
    return dis;

}


int main(){
    vector<vector<int>>mat={
        {0,0,0},{0,1,0},{0,0,0}
    };
    int delRow[]={-1,0,+1,0};
    int delCol[]={0,+1,0,-1};
  vector<vector<int>>ans=  updateMatrix(mat,delCol,delRow);
       for (auto row : ans) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
      }

    return 0;

}