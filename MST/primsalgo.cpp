#include <iostream>
#include<vector>
#include<queue>
using namespace std;



int spanningTree(vector<pair<int,int>>adj[],int V){
    vector<int>vis(V,0);
    int sum=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   
   // push the weight and node
    pq.push({0,0});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int weight=it.first;
        // greedy approach 
        if(vis[node]==1) continue;
        sum+=weight;
        vis[node]=1;
        for(auto &itr:adj[node]){
            int adjNode=itr.first;
            int edW=itr.second;

            if(!vis[adjNode]){
                pq.push({edW,adjNode});
            }
        }
    }
    return sum;


}



int main(){
    vector<vector<int>>edges={
        {0, 1, 5}, {1, 2, 3}, {0, 2, 1}
};

int V=3;


// consturct the adjacency list
 vector<pair<int,int>>adj[V];


 for(auto it:edges){
    int u=it[0];
    int v=it[1];
    int w=it[2];
    adj[u].push_back({v,w});
     adj[v].push_back({u,w});

 }

 int mstSum=spanningTree(adj,V);
 cout<<"The minimum spanning tree sum is:"<<" "<<mstSum<<endl;

 return 0;




}
