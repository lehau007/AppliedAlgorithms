#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

// Anh thuong em, em thuong ai

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;

    int cur_len = 1; vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0; bool pre_is_even = true;
    if (a[0] % 2 == 1)
        pre_is_even = false;

    for (int i = 1; i < n; i++) {
        if (pre_is_even) {
            if (a[i] % 2 == 1) {
                cur_len += 1;
                ans = max(ans, cur_len);
                pre_is_even = false;
            } else {
                cur_len = 1;
            }
        } else {
            if (a[i] % 2 == 0) {
                cur_len += 1;
                ans = max(ans, cur_len);
                pre_is_even = true;
            } else {
                cur_len = 1;
            }
        }
    }

    if (ans == 0 || ans == 1) {
        cout << '0';
    } else {
        cout << ans;
    }
    return 0;
}
