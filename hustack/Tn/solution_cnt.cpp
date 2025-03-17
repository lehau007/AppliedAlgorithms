#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

int n, m; vector<int> a, visited;

int backtracking(int idx, int cost) {
    if (cost > m) 
        return 0;

    if (idx == n) {
        if (cost == m) {
            return 1;
        } 
        return 0;
    }
    
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += backtracking(idx + 1, cost + a[idx] * i);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << backtracking(0, 0);
    return 0;
}