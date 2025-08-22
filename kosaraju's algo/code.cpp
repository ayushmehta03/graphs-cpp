#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs2(int node, vector<int>& vis, vector<int> adjT[]) {
    vis[node] = 1;
    for (auto it : adjT[node]) {
        if (!vis[it]) dfs2(it, vis, adjT);
    }
}

void dfs1(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs1(it, vis, adj, st);
    }
    st.push(node);
}

int kosarajuAlgo(vector<int> adj[], int n) {
    vector<int> vis(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i, vis, adj, st);
    }

    vector<int> adjT[n];
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    fill(vis.begin(), vis.end(), 0);

    int scc = 0;
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!vis[node]) {
            scc++;
            dfs2(node, vis, adjT);
        }
    }

    return scc;
}

int main() {
    int n = 5; 
    vector<int> adj[n];

    vector<pair<int,int>> edges = {
        {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}
    };

    for (auto it : edges) {
        adj[it.first].push_back(it.second);
    }

    int ans = kosarajuAlgo(adj, n);
    cout << "The number of strongly connected components: " << ans << "\n";
}
