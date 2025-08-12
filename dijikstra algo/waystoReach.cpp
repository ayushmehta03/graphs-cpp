#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countPaths(int n, vector<pair<int,int>> adj[]) {
    vector<long long> dist(n, 1e15);
    vector<int> ways(n, 0);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    int mod = 1e9 + 7;
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0}); // {distance, node}

    while (!pq.empty()) {
        auto [currDist, node] = pq.top();
        pq.pop();

        if (currDist > dist[node]) continue;

        for (auto &[adjNode, weight] : adj[node]) {
            if (dist[adjNode] > currDist + weight) {
                dist[adjNode] = currDist + weight;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dist[adjNode] == currDist + weight) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}

int main() {
    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    int n = 7;
    vector<pair<int,int>> adj[n];

    for (auto &it : roads) {
        int u = it[0], v = it[1], w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int result = countPaths(n, adj);
    cout << "Number of shortest paths from node 0 to node " << n - 1 << " = " << result << "\n";

    return 0;
}
