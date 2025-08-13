#include<iostream>
#include<vector>

// used for negative cycle too where dijkstra algo fails
using namespace std;
vector<int>bellmanFord(int V,int src,vector<vector<int>>&edges){
    vector<int>distance(V,1e8);
    distance[src]=0;
    for(int i=0;i<V-1;i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];

            if(distance[u]!=1e8&&distance[u]+w<distance[v]){
                distance[v]=distance[u]+w;
            }

        }
    }
    for(auto it:edges){
        int u=it[0];
            int v=it[1];
            int w=it[2];
                        if(distance[u]!=1e8&&distance[u]+w<distance[v]){
                            return {-1};
            }


    }
    return distance;
}

int main(){
    int V=5;
     vector<vector<int>> edges = {
        {1, 3, 2}, 
        {4, 3, -1},
        {2, 4, 1}, 
        {1, 2, 1},
        {0, 1, 5} 
    };

    int src=0;
    vector<int>ans=bellmanFord(V,src,edges);

    for(int dist:ans){
        cout<<dist<<" ";
    }
    return 0;

}

