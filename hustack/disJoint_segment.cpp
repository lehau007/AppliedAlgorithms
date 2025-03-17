#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <stdlib.h>

using namespace std;

// Anh thuong em, em thuong ai

const int MOD = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;

int n, *diff, max_right = -MOD;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    diff = (int*)malloc(1000002 * sizeof(int));

    for (int i = 0; i < 1000002; i++) {
        diff[i] = 0;
    }

    int left, right;
    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        diff[left] += 1; diff[right + 1] -= 1;
        max_right = max(max_right, right);
    }

    int cur = 0, ans = 0;
    int pre = -1;
    for (int i = 0; i < max_right + 1; i++) {
        cur += diff[i];
        // cout << cur << endl;
        if ((cur == 1 || cur == 0)&& diff[i] != 0) {
            ans += 1;
        }
    }

    cout << ans;

    free(diff);
    return 0;
}
