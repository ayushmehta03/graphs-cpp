#include <iostream>
#include <vector>
using namespace std;



bool dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathVis){
    vis[node]=1;
    pathVis[node]=1;
    for(int v:adj[node]){
        if(!vis[v]){
            if(dfs(v,adj,vis,pathVis)) 
            return true;
        }
        else if(pathVis[v]){
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}


int main(){
    int n=4;
    vector<pair<int,int>>edges={
       {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}  
    };
    vector<vector<int>>adj(n);
    for(auto &[u,v]:edges){
        adj[u].push_back(v);
    }
    vector<int>vis(n,0),pathVis(n,0);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis)){
                cout<<"Cycle detcted int eh graph"<<endl;
                return 0;
            }
        }
    }
    cout<<"No cycle detcted in the graph";
    return 0;
}