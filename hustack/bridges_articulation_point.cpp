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
vector<vector<int>> adj;
vector<int> N, low, parents;
vector<bool> is_apoint; int bridge_cnt = 0;
int num_visit = 0;

void dfs(int cur) {
    N[cur] = num_visit; low[cur] = num_visit;
    num_visit += 1;

    int children = 0;
    for (int next : adj[cur]) {
        if (N[next] == -1) {
            parents[next] = cur;
            dfs(next);
            low[cur] = min(low[cur], low[next]);
            children += 1;
            // Articulation point conditions
            // Case 1: root have 2 independent subtrees
            if (parents[cur] == cur && children > 1) {
                is_apoint[cur] = true;
            }

            // Case 2: not root and have low[next] >= N[cur]
            if (parents[cur] != cur && low[next] >= N[cur]) {
                is_apoint[cur] = true;
            }

            // Bridge condition
            if (low[next] > N[cur])
                bridge_cnt += 1;
        } else if (parents[cur] != next) {
            // Back edge condition
            low[cur] = min(low[cur], N[next]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    // Resize global declared vector
    adj.resize(n);
    N.resize(n, -1);
    low.resize(n, -1);
    parents.resize(n, -1);
    is_apoint.resize(n, false);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u -= 1; v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (N[i] == -1) {
            parents[i] = i;
            dfs(i);
        }
    }

    int art_point = 0;
    for (bool isright : is_apoint)
        if (isright)
            art_point += 1;

    cout << art_point << " " << bridge_cnt;
    return 0;
}
