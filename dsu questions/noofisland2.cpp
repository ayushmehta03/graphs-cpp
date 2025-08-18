#include <iostream>
#include<vector>
using namespace std;

class DisjointSet{
 vector<int>size,parent;
 public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUParent(int node){
        if(parent[node]==node) return;
        return parent[node]=findUParent(parent[node]);
    }
    void unionBySize(int u,int v){
        int uniP_u=findUParent(u);
        int uniP_v=findUParent(v);
        if(uniP_u==uniP_v) return;
        if(size[uniP_u]<size[uniP_v]){
            parent[uniP_u]=uniP_v;
            size[uniP_v]+=size[uniP_u];
        }
        else{
          parent[uniP_v]=uniP_u;
            size[uniP_u]+=size[uniP_v];

        }
    }

};

bool isValid(int nRow, int nCol, int r, int c){
    return nRow>=0&&nRow<r&&nCol>=0&&nCol<c;

}

vector<int>findIslands(vector<vector<int>>&operators,int n,int m){
 DisjointSet ds(m*n);
    int vis[n][m];
    memset(vis,0,sizeof vis);
    int cnt=0;
    vector<int>ans;
    for(auto it:operators){
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col]=1;
        cnt++;

        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};

        for(int idx=0;idx<4;idx++){
            int adjRow=row+delRow[idx];
            int adjCol=col+delCol[idx];
            if(isValid(adjRow,adjCol,n,m)){
                if(vis[adjRow][adjCol]){
                    int nodeNo=row*m+col;
                    int adjnodeNo=adjRow*m+adjCol;
                    if(ds.findUParent(nodeNo)!=ds.findUParent(adjnodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo,adjnodeNo);
                    }
                }
            }

        }
        ans.push_back(cnt);

    }
    return ans;


}


int main(){
    vector<vector<int>>operators={
        {1,1},{0,1},{3,3},{3,4}
    };
    int row=4;
    int col=5;
    vector<int>islandSol=findIslands(operators,row,col);
    for(auto it:islandSol){
        cout<<it<<" ";
    }

}