#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis,stack<int>&st){
   vis[node]=1;
   for(int i:adj[node]){
    if(!vis[i]){
        dfs(i,adj,vis,st);
    }

   }
   // while returing back push the node to the stack
   st.push(node);
}
// consturct the adjcanet list
vector<vector<int>>constructadj(int V,vector<vector<int>>&edges){
 vector<vector<int>>adj(V);
 for(auto it:edges){
    adj[it[0]].push_back(it[1]);
 }
 return adj;
}
vector<int>topologicalSort(int V,vector<vector<int>>&edges){
    stack<int>st;
    vector<bool>vis(V,false);
    vector<vector<int>>adj=constructadj(V,edges);
// for component
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }
    vector<int>ans;
    // use the principle of stak lifo
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;

}


int main(){
      int v = 6;
    vector<vector<int>> edges = {{2, 3}, {3, 1}, {4, 0}, {4, 1}, {5, 0}, {5, 2}};

  vector<int>ans=topologicalSort(v,edges);

  for(auto a:ans){
    cout<<a<<" ";
  }
  cout<<endl;
  return 0;


}
