#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &graph, vector<int> &color) {
    for (int v : graph[node]) {
        if (color[v] == -1) {
            color[v] = !color[node]; 
            if (dfs(v, graph, color) == false)
                return false;
        }
        else if (color[v] == color[node]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    int n = graph.size();
    vector<int> color(n, -1);  

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            if (dfs(i, graph, color) == false) {
                cout << "Graph is NOT bipartite" << endl;
                return 0;
            }
        }
    }

    cout << "Graph is bipartite" << endl;
    return 0;
}
