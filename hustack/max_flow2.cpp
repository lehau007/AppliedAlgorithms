#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int n, m, s, t; cin >> n >> m >> s >> t;
vector<vector<pair<int, pair<int, int>>>> adj;
vector<vector<pair<int, pair<int, int>>>> reverse_adj;


vector<bool> visited; int ans = 0;
void dfs(int cur, int cur_min) {
    if (cur == t)
        ans += cur_min;

    visited[cur] = true;
    for (auto& neigh : adj[cur]) {
        if (visited[neigh])
            continue;

        if ()
    }

    visited[cur] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m, s, t; cin >> n >> m >> s >> t;
    adj.resize(n);
    reverse_adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int src, dest, w; cin >> src >> dest >> w;
        adj[src].push_back({dest, {0, w});
    }


    return 0;
}

