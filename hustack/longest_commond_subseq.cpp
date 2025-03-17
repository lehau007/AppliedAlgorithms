#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Anh thuong em, em thuong ai.

// Problem details:

/*
Given two arrays a1, an and b1, bm
find the longest common subseq
subseq does't need to continuous like sub array
*/

vector<vector<int>> memo;
vector<int> a, b;
int n, m;

int dp(int i, int j) {
    if (i == n)
        return 0;
    if (j == m)
        return 0;

    // cout << i << " " << j << ": " << memo[i][j] << endl;
    if (memo[i][j] != -1)
        return memo[i][j];

    if (a[i] == b[j]) {
        memo[i][j] = 1 + dp(i + 1, j + 1);
        return memo[i][j];
    } else {
        int ans = 0;
        // ans = dp(i + 1, j);
        ans = max(ans, dp(i, j + 1));
        memo[i][j] = ans;
        return ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n; cin >> m;

    a.resize(n);
    b.resize(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    memo.resize(n, vector<int> (m, -1));
    cout << dp(0, 0);
    return 0;
}
