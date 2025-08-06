#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// function to get the shortest distnace
vector<int>shortestPath(vector<vector<int>>&adj,int src){
    // calciulate the sixe of adjacency list
 int n=adj.size();
 // declare distance array with all elents as infinty for now
    vector<int>dis(n,1e9);
    // starting point is 0 
    dis[src]=0;
    // declare queue ds core bfs logic 
    queue<pair<int,int>>q;
    // push the point and the distance
    q.push({src,dis[src]});
    while(!q.empty()){
        // take the point
        int node=q.front().first;
        // take the distance
        int distance=q.front().second;
        
        q.pop();
        for(auto it:adj[node]){
            // if the distance present inside dis is greater than the current distance exceute
         if(dis[it]>distance+1){
            // place the new distnace value
            dis[it]=distance+1;
            // push the point and the distance in the queue
            q.push({it,dis[it]});
         }
        }

    }
    return dis;
}



int main(){
    vector<vector<int>>edges={
    {1,3},{0,2,3},{1,6},{0,4},{3,5},{4,6},{2,5,7,8},{6,8},{6,7}
    };
int n=edges.size();
// create adjeceny list
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
    for(auto it:edges[i]){
        adj[i].push_back(it);
    }
}
// print the shortes distance 
  vector<int>distance=shortestPath(adj,0);
 for (int i = 0; i < n; i++) {
        if (distance[i] != 1e9)
            cout << "Shortest distance from 0 to " << i << " = " << distance[i] << endl;
        else
            cout << "Node " << i << " is not reachable from source." << endl;
    }
  
 return 0;
}