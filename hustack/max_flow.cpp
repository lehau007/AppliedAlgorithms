#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Anh thuong em, em thuong ai

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

int n; int m;
vector<vector<pair<int, int>>> adj;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        u -= 1; v -= 1;

        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    return 0;
}
