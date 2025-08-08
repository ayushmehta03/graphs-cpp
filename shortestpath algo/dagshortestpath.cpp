#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void topoSort(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node]=true;
    for(auto &it:adj[node]){
        int neighbour=it.first;
        if(!visited[neighbour]){
            topoSort(neighbour,adj,visited,st);
        }
    }

    st.push(node);
}

vector<int>shortestPathDAG(int n,vector<vector<pair<int,int>>>&adj,int src){
vector<bool>vis(n,false);
stack<int>st;
for(int i=0;i<n;i++){
    if(!vis[i]){
        topoSort(i,adj,vis,st);
    }
}
vector<int>distance(n,INT_MAX);
distance[src]=0;
while(!st.empty()){
    int node=st.top();
    st.pop();
    for(auto it:adj[node]){
        int v=it.first;
        int wt=it.second;
        if(distance[node]+wt<distance[v]){
            distance[v]=distance[node]+wt;
        }
    }
}
return distance;
}


int main(){
    // the edges vector contain start,to and the weight
    vector<vector<int>> edges = {
    {0, 1, 2},
    {0, 4, 1},
    {1, 2, 3},
    {2, 3, 6},
    {4, 2, 2},
    {4, 5, 4},
    {5, 3, 1}
};

int n=6;
vector<vector<pair<int,int>>>adj(n);
for(auto it:edges){
    int u=it[0];
    int v=it[1];
    int wt=it[2];
    adj[u].push_back({v,wt});
}
    int src=0;

vector<int>dist=shortestPathDAG(n,adj,src);
}
