#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, tar; cin >> n >> tar;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1, ans = tar - a[i];
        while (l < r) {
            if (a[l] + a[r] == ans) {
                cnt += 1;
                cnt = cnt % mod;
                int after_l = l + 1;
                int before_r = r - 1;
                if (a[after_l] == a[l])
                    l += 1;
                else if (a[before_r] == a[r])
                    r -= 1;
                else {
                    l += 1;
                    r -= 1;
                }
            } else if (a[l] + a[r] < ans)
                l += 1;
            else
                r -= 1;
        }
    }

    cout << cnt % mod;
    return 0;
}
