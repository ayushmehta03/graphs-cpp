#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUParent(u), pv = findUParent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

bool isValid(int nRow,int nCol,int n){
    return nRow>=0 && nRow<n && nCol>=0 && nCol<n;
}

int findMaxSize(vector<vector<int>>&grid,int n){
    DisjointSet ds(n*n);
    int delRow[4]={-1,0,1,0};
    int delCol[4]={0,1,0,-1};

    // connect 1's
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col]==0) continue;
            for(int i=0;i<4;i++){
                int nRow=row+delRow[i], nCol=col+delCol[i];
                if(isValid(nRow,nCol,n) && grid[nRow][nCol]==1){
                    int nodeNo=row*n+col;
                    int adjNodeNo=nRow*n+nCol;
                    ds.unionBySize(nodeNo,adjNodeNo);
                }
            }
        }
    }

    int mxSize=0;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if (grid[row][col] == 1) continue;
            set<int> components;
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i], nCol = col + delCol[i];
                if (isValid(nRow, nCol, n) && grid[nRow][nCol] == 1) {
                    int node = nRow * n + nCol;
                    components.insert(ds.findUParent(node));
                }
            }
            int sizeTotal = 1;
            for (auto it : components) sizeTotal += ds.size[it];
            mxSize = max(mxSize, sizeTotal);
        }
    }

    for (int cellNo = 0; cellNo < n * n; cellNo++) {
        mxSize = max(mxSize, ds.size[ds.findUParent(cellNo)]);
    }
    return mxSize;
}

int main(){
    vector<vector<int>>grid={{1,0},{0,1}};
    int n=grid.size();
    cout<<"The maximum size after changing one 0 is: "<<findMaxSize(grid,n);
}
