#include<iostream>
#include<queue>
#include<vector>
using namespace std;



bool isDetect(int src,vector<vector<int>>adj,vector<bool>&visited,int parent){
    visited[src]=true;
    queue<pair<int,int>>q;
    q.push({src,parent});
    while(!q.empty()){
     int node=q.front().first;
     parent=q.front().second;
     for(auto adjacentNode:adj[node]){
        if(!visited[adjacentNode]){
            visited[adjacentNode]=true;
            q.push({adjacentNode,parent});

        }
        else if(parent!=adjacentNode){
            return true;
        }
     }
     return false;
    }
}


// forming the adjacent list
vector<vector<int>>constructadj(int V,vector<vector<int>>&edges){
    vector<vector<int>>adj(V);
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    return adj;
}


bool isCycle(int V,vector<vector<int>>&edges){
    vector<vector<int>>adj=constructadj(V,edges);
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(isDetect(i,adj,visited,-1)) return true;
        }
    }
    return false;


}


int main(){
    int V=5;
    vector<vector<int>>edges={
        {0,1},{0,2},{0,3},{1,2},{3,4}
    };
    if(isCycle(V,edges)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
  return 0;

}