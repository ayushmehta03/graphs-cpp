#include <iostream>
#include<vector>
#include<queue>
using namespace std;

bool topoSort(vector<int>adj[],int V){
    vector<int>inDegree(V);
    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            inDegree[it]++;

        }
    }
    queue<int>q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0) q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node] ){
        inDegree[it]--;
        if(inDegree[it]==0) q.push(it);
        }

    }
    if(topo.size()==V) return true;
    return false;

}



bool canFinsh(vector<vector<int>>&edges,int V){
    vector<int>adj[V];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }
    if(topoSort(adj,V)==true) return true;
    return false;

}



int main(){
    vector<vector<int>>prerequisites={
       {1,0} 
    };
    int numCourses=2;
    if(canFinsh(prerequisites,numCourses)){
        cout<<"Yes it is possible";
    }
    else{
        cout<<"not possible to take courses";
    }
    return 0;



}