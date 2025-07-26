#include <iostream>
#include<queue>
#include<vector>
using namespace std;

bool dfs(int node,vector<vector<int>>&adj,vector<int>&visited,int parent){
    visited[node]=1;
    for(auto adjacentNode:adj[node]){
        if(!visited[adjacentNode]){
            if(dfs(adjacentNode,adj,visited,node)==true) return true;

        }
        else if(adjacentNode!=parent){
            return true;
        }
    }
    return false;

}

vector<vector<int>>constructAdj(vector<vector<int>>&edges,int V){
 vector<vector<int>>adj(V);
 for(auto it:edges){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
 }
 return adj;

}


bool isCycle(vector<vector<int>>&edges,int V){
    vector<vector<int>>adj=constructAdj(edges,V);
    vector<int>visited(V,0);
    for(int i=0;i<V;i++){
        if(!visited[i]){
          if(  dfs(i,adj,visited,-1)==true) return true;

        }
        return false;
    }

}



int main(){
    vector<vector<int>>edges={{0,1},{0,2},{0,3},{1,2},{3,4} };
    int V= edges.size();
   if( isCycle(edges,V) ){
    cout<<"true"<<endl;
   }
   else{
    cout<<"false"<<endl;
   }

}