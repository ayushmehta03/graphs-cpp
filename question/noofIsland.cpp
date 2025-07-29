#include<iostream>
#include<vector>
using namespace std;
 

//  dfs approach 
void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();

    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        // new row and col checking all four directions 
        int nRow=row+delRow[i];
        int nCol=col+delCol[i];
        // condition check for new row new column 
        if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m&&!vis[nRow][nCol]&&grid[nRow][nCol]=='1'){
            dfs(nRow,nCol,vis,grid);
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
            dfs(i,j,vis,grid);
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
 cout<<"The total no of island that can be formed:"<<ans<<endl;
}