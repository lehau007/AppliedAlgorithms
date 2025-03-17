#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

// Anh thuong em, em thuong ai

#define int long long

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u -= 1; v -= 1;
        adj[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t; s -= 1; t -= 1;
    queue<int> q;
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        auto cur = q.front(); q.pop();

        for (auto neighbor : adj[cur]) {
            int v = neighbor.first, w = neighbor.second;

            if (dist[cur] + w < dist[v]) {
                dist[v] = dist[cur] + w;
                q.push(v);
            }
        }
    }

    if (dist[t] == INT_MAX) {
        cout << -1;
    } else
        cout << dist[t];
    return 0;
}
