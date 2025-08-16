#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int>parent,size;
public:
    DisjointSet(int n){
    size.resize(n+1,1);
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
     parent[i]=i;

    }


    }
    int findUPar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionBysize(int u,int v){
        int uniP_u=findUPar(u);
        int uniP_v=findUPar(v);
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
      DisjointSet ds(7);
    ds.unionBysize(1,2);
    ds.unionBysize(2,3);
    ds.unionBysize(4,5);
    ds.unionBysize(6,7);
    ds.unionBysize(5,6);
    ds.unionBysize(3,7);

    if(ds.findUPar(3)==ds.findUPar(7)){
        cout<<"Same";
    }
    else{
        cout<<"Not same";
    } 

}