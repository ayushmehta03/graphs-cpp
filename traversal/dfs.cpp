#include<iostream>
using namespace std;
#include<vector>

void dfs(int node,vector<int>&visited,vector<vector<int>>&adj,vector<int>&ls){
    visited[node]=1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,visited,adj,ls);
        }
    }

}
vector<int>dfsFind(vector<vector<int>>&adj,int n){
    vector<int> visited(n, 0); // initialize all to 0
    
    int start=0;
    vector<int>ls;
    dfs(start,visited,adj,ls);
    return ls;

}

int main(){
vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
int n=adj.size();
    vector<int> ans = dfsFind(adj,n);
    // print all the dfs eleemnts
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}