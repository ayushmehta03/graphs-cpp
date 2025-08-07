#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> dijikstraAlgo(vector<pair<int,int>> adj[], vector<int>& parent, vector<int>& dis, int src) {
    dis[src] = 0;
    int n = 6;

    // Correct order: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop(); // missing in your code
        int distance = it.first;
        int node = it.second;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;
            if (distance + weight < dis[adjNode]) {
                dis[adjNode] = distance + weight;
                pq.push({dis[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    // if destination not reachable
    if (dis[n - 1] == 1e9) return {};

    vector<int> path;
    int node = n - 1;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {2, 3, 6},
        {4, 2, 2},
        {4, 5, 4},
        {5, 3, 1}
    };

    int n = 6;
    vector<pair<int, int>> adj[n];

    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    vector<int> dis(n, 1e9);

    vector<int> ans = dijikstraAlgo(adj, parent, dis, 0);

    if (ans.empty()) {
        cout << "No path found from 0 to " << n - 1 << endl;
    } else {
        cout << "The shortest path is: ";
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
}
