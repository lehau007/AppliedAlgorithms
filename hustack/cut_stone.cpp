#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int mod = 1e9 + 7;

int t; int l, w, h;
vector<vector<vector<int>>> memo_min(101, vector<vector<int>>(101, vector<int>(101)));

void set_value(int length, int width, int height, int val) {
    memo_min[length][width][height] = val;
    memo_min[length][height][width] = val;
    memo_min[width][length][height] = val;
    memo_min[width][height][length] = val;
    memo_min[height][length][width] = val;
    memo_min[height][width][length] = val;
}

int recursion(int length, int width, int height) {
    if (memo_min[length][width][height] != -1)
        return memo_min[length][width][height];

    // cout << length << " - " << width << " . " << height << endl;

    // Apply three cases
    // Case 1: follow length
    int ans = INT_MAX;
    int mid = length / 2;
    for (int i = 1; i <= mid; i++) {
        ans = min(ans, recursion(i, width, height) + recursion(length - i, width, height));
    }

    // Case 2: follow width
    mid = width / 2;
    for (int i = 1; i <= mid; i++) {
        ans = min(ans, recursion(length, i, height) + recursion(length, width - i, height));
    }

    // Case 3: follow height
    mid = height / 2;
    for (int i = 1; i <= mid; i++) {
        ans = min(ans, recursion(length, width, i) + recursion(length, width, height - i));
    }

    set_value(length, width, height, ans);
    return ans;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> l >> w >> h;
        // cout << l << w << h;

        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                for (int k = 0; k < 101; k++) {
                    memo_min[i][j][k] = -1;
                }
            }
        }

        memo_min[1][1][1] = 1;
        memo_min[0][0][0] = 0;

        // cout << "pass";
        int n; cin >> n; int ans = 0;
        for (int i = 0; i < n; i++) {
            int u, v, c; cin >> u >> v >> c;
            set_value(u, v, c, 0);
        }

        cout << recursion(l, w, h) << endl;
    }
    return 0;
}
