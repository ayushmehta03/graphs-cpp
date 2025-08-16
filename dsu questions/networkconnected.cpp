// leetcode 1319
#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
public:
    vector<int>parent,size;
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;

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
    vector<vector<int>> connections={
        {0,1},{0,2},{0,},{1,2},{1,3}
    };
    int n=6;

    DisjointSet ds(n);
    int cntExtras=0;
    for(auto it:connections){
        int u=it[0];
        int v=it[1];
        if(ds.findParent(u)==ds.findParent(v)) cntExtras++;
        else{
            ds.unionBySize(u,v);
        }

    }
    int cntC=0;
    for(int i=0;i<n;i++){
       if(ds.parent[i]==i) cntC++;
    }
    int ans=cntC-1;
    if(cntExtras>=ans){
        cout<<"The minimum opertaion required is"<<" "<<ans;

    }
    else{
        cout<<"It is not possible to connect them ";
    }
    return 0;

    

}