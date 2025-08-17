#include<iostream>
#include<vector>
#include<map>
using namespace std;

class DisjointSet{
    vector<int>size,parent;
public:
    DisjointSet (int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
     if(parent[node]==node) return node;
         return parent[node]=findParent(parent[node]);

    }
     void unionBySize(int u,int v){

        int uniP_u=findParent(u);
        int uniP_v=findParent(v);
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



int main(){
    vector<vector<int>>stones={
        {0,0},{0,1},{1,0},{1,2},{2,1},{2,2}
    };
    int n=stones.size();
    int maxRow=0,maxCol=0;
    for(auto it:stones){
        maxRow=max(maxRow,it[0]);
        maxCol=max(maxCol,it[1]);

    }
    DisjointSet ds(maxRow+maxCol+1);

    unordered_map<int,int>stoneNodes;

    for(auto it:stones){
        int nodeRow=it[0];
        int nodeCol=it[1]+maxRow+1;
        ds.unionBySize(nodeRow,nodeCol);
        stoneNodes[nodeRow]=1;
         stoneNodes[nodeCol]=1;


    }
    int cnt=0;
    for(auto it:stoneNodes){
            if(ds.findParent(it.first)==it.first){
                cnt++;
            }
        }
        int ans=n-cnt;
        cout<<"The max stones can be removed is:"<< " "<<ans;





}

