#include<iostream>
#include<vector>
using namespace std;
// construct disjoint set class 
// tc to find connecetd compo is o(4 alpha)


class DisjointSet{
    vector<int>rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionbyRank(int u,int v){
        int uniP_u=findUPar(u);
        int uniP_v=findUPar(v);
        if(uniP_u==uniP_v) return;
        if(rank[uniP_u]<rank[uniP_v]){
            parent[uniP_u]=uniP_v;
        }
        else if(rank[uniP_v]<rank[uniP_u]){
        parent[uniP_v]=uniP_u;

        }
        else{
            parent[uniP_u]=parent[uniP_v];
            rank[uniP_u]++;
        }

    }

};



int main(){
    DisjointSet ds(7);
    ds.unionbyRank(1,2);
    ds.unionbyRank(2,3);
    ds.unionbyRank(4,5);
    ds.unionbyRank(6,7);
    ds.unionbyRank(5,6);
    ds.unionbyRank(3,7);

    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"Same";
    }
    else{
        cout<<"Not same";
    } 





return 0;


    


}