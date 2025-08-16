#include<iostream>
#include<vector>
using namespace std;
class DisJointSet{
 vector<int>parent,size;
 public:
  DisJointSet(int n){
    parent.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
  }
  int findUParent(int node){
    if(node==parent[node]) return node;
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

int main() {
    vector<vector<int>> edges = {
        {0, 1, 5}, {1, 2, 3}, {0, 2, 1}
    };
    int V = 3;

    // Proper adjacency list declaration
    vector<vector<pair<int,int>>> adj(V);

    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<pair<int,pair<int,int>>> setV;
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            int adjNode = it.first;
            int wt = it.second;
            int node = i;
            setV.push_back({wt, {node, adjNode}});
        }
    }
    DisJointSet ds(V);
    sort(setV.begin(),setV.end());

    int mstW=0;
    for(auto it:setV){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(ds.findUParent(u)!=ds.findUParent(v)){
            mstW+=wt;
            ds.unionBySize(u,v);
        }
    }
    return mstW;



}
