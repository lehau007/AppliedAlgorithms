#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Anh thuong em, em thuong ai

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;


struct Edge {
    int u, v, w;
};

int n; vector<Edge> edges;
vector<vector<pair<int, int>>> adj;
vector<int> p, d, N, f;

class Disjoint_set {
private:
    vector<int> parent;
    vector <int> rank;
    vector<int> ans;

public:
    Disjoint_set(int n) {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        rank.resize(n, 0);
        ans.resize(n, 0);
    }

    int find_parent(int u) {
        if (u == parent[u])
            return u;
        return find_parent(parent[u]);
    }

    int find_parent_and_insert(int u, int value) {
        ans[u] += value;
        if (u == parent[u]) {
            return u;
        }
        return find_parent_and_insert(parent[u], value);
    }

    bool union_find(int u, int v) {

        return true;
    }

    void solve(int u, int v, int w) {
        u = find_parent_and_insert(u, w);
        v = find_parent_and_insert(v, w);

        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] == rank[v]) {
            parent[v] = u;
            rank[u] += 1;
        } else {
            parent[u] = v;
        }
    }

    void find_ans() {
        int res = 0;
        for (int i : ans) {
            res = max(i, res);
        }

        cout << res;
        return;
    }
};

int dfs2(int cur, int parent) {
    if (cur == -1)
        return 0;

    int ans = 0, plus = 0, i = 0;
    for (auto& neigh : adj[cur]) {
        if (neigh.first != parent) {
            int tmp = dfs2(neigh.first, cur);
            ans += tmp;
        } else {
            plus = adj[cur][i].second;
        }
        i += 1;
    }
    return ans + plus;
}

int dfs1(int cur, int parent) {
    f[cur] += dfs2(parent, cur);

    int ans = 0, plus = 0, i = 0;
    for (auto& neigh : adj[cur]) {
        if (neigh.first != parent) {
            int tmp = dfs1(neigh.first, cur);
            ans += tmp;
        } else {
            plus = adj[cur][i].second;
        }
        i += 1;
    }

    f[cur] += ans;
    return ans + plus;
}

void dfs12(int u) {
    for (auto& neigh : adj[u]) {
        int v = neigh.first, w = neigh.second;

        if (p[v] == 0) {
            p[v] = u;
            dfs12(v);
            d[u] = d[u] + d[v] + N[v] * w;
            N[u] = N[u] + N[v];
        }
    }
}

void phase1() {
    for (int v = 1; v <= n; v++) {
        p[v] = 0;
        d[v] = 0;
        N[v] = 1;
        f[v] = 0;
    }
    p[1] = 1; dfs12(1);
}

void dfs22(int u) {
    for (pair<int, int> &neigh : adj[u]) {
        int v = neigh.first, w = neigh.second;

        if (p[v] == 0) {
            int F = f[u] - (d[v] + N[v] * w);
            f[v] = F + d[v] + w * (n - N[v]);
            p[v] = u; dfs22(v);
        }
    }
}

void phase2() {
    for (int i = 1; i <= n; i++) {
        p[i] = 0;
    }
    f[1] = d[1]; p[1] = 1; dfs22(1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; adj.resize(n + 1); f.resize(n + 1);
    p.resize(n + 1); d.resize(n + 1, 0); N.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    phase1(); phase2();

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[i]);
    }

    cout << res;
    return 0;
}
