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

void dfs(int cur, int color) {
    visited[cur] = color;

    for (int neigh : adj[cur]) {
        if (visited[neigh] != -1) {
            if (visited[neigh] != color) {
                cout << "Not bipartite";
                exit(0);
            }
        } else {
            dfs(neigh, 1 - color);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    return 0;
}
