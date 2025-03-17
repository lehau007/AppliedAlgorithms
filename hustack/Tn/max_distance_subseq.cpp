#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

const int maxN = 100002;
int n, c;

bool isvalid(vector<int> &dist, int mid) {
    if (c == 0 || c == 1)
        return true;
    int cnt = 1, pre = dist[0];
    for (int i = 1; i < n; i++) {
        if (dist[i] - pre >= mid) {
            pre = dist[i];
            cnt += 1;
        }

        if (cnt >= c) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;

    while (t--) {
        cin >> n; cin >> c;
        vector<int> dist(n);
        for (int i = 0; i < n; i++) {
            cin >> dist[i];
        }

        sort(dist.begin(), dist.end());

        int ans = 0;
        int r = 1000000000, l = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (isvalid(dist, m)) {
                l = m + 1;
                ans = m;
            } else {
                r = m - 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
