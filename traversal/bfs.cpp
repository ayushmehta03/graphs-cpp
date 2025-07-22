#include <iostream>
using namespace std;
#include <vector>
#include<queue>
vector<int>bfs(vector<vector<int>>&adj){
    // take the size of adjacent vector 
    int n= adj.size();

    // starting point is 0
    int s=0;

    // declare vector for storing the bfs
    vector<int>res;

    // declare queue for fifo mechanism
    queue<int>q;

    // declare tracker visited vector
    vector<bool>visited(n,false);
    

    // markk the starting point as true
    visited[s]=true;
    // push it to the queue
    q.push(s);

    // traverse till the queue is not empty
    while(!q.empty()){
        // store the top element of queue
        int curr=q.front();

        // pop it and push it to the res vector
        q.pop();
        res.push_back(curr);

        // keep the track if it is visited or not if not visited push it to the queue
        for(int x:adj[curr]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
    // return the vector 
    return res;

}

int main()  {

    vector<vector<int>> adj = {{1,2}, {0,2,3}, {0,4}, {1,4}, {2,3}};
    vector<int> ans = bfs(adj);
    // print all the bfs eleemnts
    for(auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}