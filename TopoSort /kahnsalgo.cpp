#include<iostream>
#include<queue>
#include<vector>
using namespace std;


vector<vector<int>>constructAdj(vector<vector<int>>&edges,int V){
 vector<vector<int>>adj(V);
 for(auto it:edges){
    adj[it[0]].push_back(it[1]);
 }
 return adj;
}

vector<int>kahnsAlgo(vector<vector<int>>&adj,int V){
    // push the value which dont have any indegree means it will occur first as per the topo sort rule u should appear before v
    vector<int>inDegree(V,0);
    for(int i=0;i<V;i++){
     for(auto it:adj[i]){
        inDegree[it]++;
     }
    }
    // declaring the queue
 queue<int>q;
 // push the intial value with 0 to the queue
    for(int i=0;i<V;i++){
        if(inDegree[i]==0) q.push(i);
    }

    // declare the answer vector
    vector<int>topo;
    // core algo
    while(!q.empty()){
    int node=q.front();
    q.pop();
    // push q elemnts to the topo vector
    topo.push_back(node);
    
    // we will decrease the indegree of the nodes present inside adj[node]

    for(auto it:adj[node]){
        inDegree[it]--;
        // if its value will become push to the queue
        if(inDegree[it]==0) q.push(it);
    }


    }
    // return the topo vector it satisfies the condition of topo sort for u and v
    return topo;

   

}

int main(){
    // no of edges 
    int V=6;
    vector<vector<int>>edges=
    {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}};
    // creating the adjacency list
    vector<vector<int>>adj=constructAdj(edges,V);
    // kahns algo calling using bfs
    vector<int>ans=kahnsAlgo(adj,V);

    for(auto it:ans){
        cout<<it<<" ";
    }

}