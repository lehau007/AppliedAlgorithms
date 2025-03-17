#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    int ans = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] == m) {
            l += 1;
            ans += 1;
        } else if (a[l] + a[r] < m) {
            l += 1;
        } else {
            r -= 1;
        }
    }
    
    cout << ans;
    return 0;
}