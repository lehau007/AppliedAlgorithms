#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std

// Anh thương em nhiều lắm, nhưng em đâu nào hay.

const int MOD = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;

/*
Description
Cho cây T = (V,E) trong đó V = {1,…,n} là tập các đỉnh và E là tập gồm n-1 cạnh. Mỗi đỉnh v của đồ thị có trọng số w(v). Hãy chọn ra tập S các đỉnh sao cho hai đỉnh kề nhau không cùng được chọn và tổng trọng số các đỉnh được chọn là lớn nhất.
Dữ liệu
· Dòng 1: ghi số nguyên dương n (1 <= n <= 100000)
· Dòng 2: ghi n số nguyên dương w(1), w(2), …, w(n) là trọng số các đỉnh tương ứng
· Dòng i+2 (i = 1,…,n-1): ghi 2 số nguyên dương u và v là 2 đầu mút của cạnh thứ i của T
Kết quả:
· Ghi ra tổng trọng số của các đỉnh được chọn
Ví dụ
Dữ liệu
9
9 5 10 4 3 2 6 1 8
1 5
2 3
2 4
2 6
3 5
6 7
6 8
6 9
Kết quả
38
*/

const int MAXN = 100000;

vector<int> adj[MAXN + 1];  // adjacency
int weights[MAXN + 1];      // weights
long long dp[MAXN + 1][2];  // memo
bool visited[MAXN + 1];     // for dfs

void dfs(int v) {
    visited[v] = true;
    dp[v][1] = weights[v];

    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
            dp[v][0] += max(dp[u][0], dp[u][1]);
            dp[v][1] += dp[u][0];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> weights[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}

