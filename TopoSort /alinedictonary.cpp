#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> topoSort(vector<int> adj[], int K) {
    vector<int> inDegree(K, 0);
    for (int i = 0; i < K; i++) {
        for (auto it : adj[i]) {
            inDegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < K; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) q.push(it);
        }
    }

    return topo;
}

int main() {
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int N = dict.size();
    int K = 4;

    vector<int> adj[K];

    for (int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());

        for (int ptr = 0; ptr < len; ptr++) {
            if (s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');  // FIXED here
                break;
            }
        }
    }

    vector<int> topo = topoSort(adj, K);
    string ans = "";
    for (auto it : topo) {
        ans += char(it + 'a');
    }

    cout << "Alien Dictionary Order: " << ans << endl;

    return 0;
}
