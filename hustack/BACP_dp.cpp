#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> credits(n);
    for (int i = 0; i < n; ++i) {
        cin >> credits[i];
    }

    vector<vector<int>> prerequisites(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> prerequisites[i][j];
        }
    }

    vector<int> preMask(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (prerequisites[i][j] == 1) {
                preMask[j] |= (1 << i);  
            }
        }
    }

    // dp[mask][period] stores the minimal maximum load after assigning the courses in 'mask' within 'period' periods
    vector<vector<int>> dp(1 << n, vector<int>(m + 1, INF));
    dp[0][0] = 0;  // base

    // all masks
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int period = 0; period < m; ++period) {
            if (dp[mask][period] == INF) continue;

            // Try to assign
            for (int subset = mask; subset < (1 << n); subset = (subset + 1) | mask) {
                int totalLoad = 0;
                bool valid = true;

                for (int i = 0; i < n; ++i) {
                    if ((subset & (1 << i)) && !(mask & (1 << i))) {
                        // Check if prerequisites met
                        if ((mask & preMask[i]) != preMask[i]) {
                            valid = false;
                            break;
                        }
                        totalLoad += credits[i];
                    }
                }

                if (valid) {
                    int newMask = mask | subset;
                    dp[newMask][period + 1] = min(dp[newMask][period + 1], max(dp[mask][period], totalLoad));
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][m] << endl;

    return 0;
}
