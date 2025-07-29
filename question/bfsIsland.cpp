#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 

//  bfs approach 
void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    int n=grid.size();
    int m=grid[0].size();

    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    while(!q.empty()){

        int row=q.front().first;
        int col=q.front().second;
        q.pop();
    for(int i=0;i<4;i++){
        int nRow=row+delRow[i];
        int nCol=col+delCol[i];
        // condition check for new row new column 
        if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m&&!vis[nRow][nCol]&&grid[nRow][nCol]=='1'){
        vis[nRow][nCol]=1;
        q.push({nRow,nCol});
        }
    }
}
}
int isLandCount(vector<vector<char>>&grid){
    int n=grid.size();
    int m=grid[0].size();

    //declare the visited matrix for checking
    vector<vector<int>>vis(n,vector<int>(m,0));
// traverse the grid matrix
int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        // condition satisfied
        if(!vis[i][j]&&grid[i][j]=='1'){
            cnt++;
            bfs(i,j,vis,grid);
        }

        }
    }
    return cnt;
}

int main(){
    vector<vector<char>>grid = {
    {'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}
};
 int ans=isLandCount(grid);
 cout<<"The total no of island that can be formed:"<<" "<<ans<<endl;
}