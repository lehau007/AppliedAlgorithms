
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int mod = 1e9 + 7;

int n, cities, k, d, cmin = INT_MAX, ans = INT_MAX; vector<int> visited_at_cost;
vector<vector<int>> mat;

void backtrack(int cur_city, int cost, int cnt, int load) {
    if (cnt == cities) {
        int tmp = cost + mat[cur_city][0];
        ans = min(ans, tmp);
        return;
    }

    // Try to load
    for (int i = 1; i <= n; i++) {
        if (visited_at_cost[i] > -1)
            continue;

        if (load == k) {
            break;
        }

        int tmp = cost + mat[cur_city][i];
        visited_at_cost[i] = tmp;

        if (tmp + cmin * (cities - cnt) < ans) { // add cmin condition
            backtrack(i, tmp, cnt + 1, load + 1);
        }

        // backtracking
        visited_at_cost[i] = -1;
    }

    // Try to deliver
    for (int i = n + 1; i < cities; i++) {
        if (visited_at_cost[i] > -1 || visited_at_cost[i - n] == -1)
            continue;
        if (load == 0)
            break;

        int tmp = cost + mat[cur_city][i];
        visited_at_cost[i] = tmp;

        if (tmp + cmin * (cities - cnt) < ans && visited_at_cost[i] - visited_at_cost[i - n] >= d) { // add cmin condition and D condition
            backtrack(i, tmp, cnt + 1, load - 1);
        }

        // backtracking
        visited_at_cost[i] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> d;
    cities = 2 * n + 1;

    visited_at_cost.resize(cities, -1);
    mat.resize(cities, vector<int>(cities));
    for (int i = 0; i < cities; i++) {
        for (int j = 0; j < cities; j++) {
            cin >> mat[i][j];
            if (mat[i][j] > 0)
                cmin = min(cmin, mat[i][j]);
        }
    }

    backtrack(0, 0, 1, 0);

    if (ans == INT_MAX) {
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}
