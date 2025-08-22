#include<iostream>
#include<vector>
using namespace std;

int timer=0;


void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],vector<int>&mark,vector<int>adj[]){
 vis[node]=1;
 tin[node]=low[node]=timer;
 timer++;
 int child=0;
 for(auto it:adj[node]){
    if(it==parent) continue;
    if(!vis[it]){
        dfs(it,node,vis,tin,low,mark,adj);
        low[node]=min(low[node],low[it]);
        if(low[it]>=tin[node]&& parent!=-1){
            mark[node]=1;
        }
        child++;
    }
    else{
        low[node]=min(low[node],tin[it]);
    }
 }
 if(child>1 &&parent==-1){
    mark[node]=1;
 }
}

vector<int>articulationPoint(vector<int>adj[],int n){

    vector<int>vis(n,0);
    int tin[n];
    int low[n];
    vector<int>mark(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,tin,low,mark,adj);
        }
    }
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(mark[i]==1){
            ans.push_back(i);
        }
    }
    if(ans.size()==0) return {-1};
    return ans;
    
}
int main(){
 int n = 5; 

    vector<int> adj[n];

    vector<pair<int,int>> edges = {
        {0,1}, {0,2}, {1,2}, {1,3}, {3,4}
    };

    for(auto it:edges){
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }
    vector<int>sol=articulationPoint(adj,n);

    for(auto it:sol){
        cout<<it<<" ";
    }

}