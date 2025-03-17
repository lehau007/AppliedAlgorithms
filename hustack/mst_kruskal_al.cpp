#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Anh thuong em, em thuong ai?

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

struct Edge {
    int v1, v2, w;
};

class Disjoint_set {
private:
    vector<int> parent; vector<int> rank;
public:
    Disjoint_set(int n) {
        for (int i = 0; i < n; i++) {
            rank.push_back(0);
            parent.push_back(i);
        }
    }

    int find_parent(int v) {
        if (parent[v] == v)
            return v;

        return find_parent(parent[v]);
    }

    bool union_find(int u, int v) {
        // find parent
        u = find_parent(u); v = find_parent(v);

        if (u == v)
            return false;

        if (rank[u] > rank[v]) {
            parent[v] = u;
        } else if (rank[u] < rank[v]) {
            parent[u] = v;
        } else {
            rank[u] += 1;
            parent[v] = u;
        }

        return true;
    }
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;

    vector<Edge> mat(m);
    // input value
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u -= 1; v -= 1;
        mat[i].v1 = u; mat[i].v2 = v; mat[i].w = w;
    }

    sort(mat.begin(), mat.end(), compare);

    // solution()
    Disjoint_set dis_set(n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (dis_set.union_find(mat[i].v1, mat[i].v2)) {
            ans += mat[i].w;
        }
    }

    cout << ans;
    return 0;
}
