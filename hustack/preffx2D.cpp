#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            prefixSum[i][j] = a[i][j] 
                            + prefixSum[i-1][j] 
                            + prefixSum[i][j-1] 
                            - prefixSum[i-1][j-1];
        }
    }

    int Query;
    cin >> Query;

    while (Query--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        int result = prefixSum[r2][c2] 
                   - prefixSum[r1-1][c2] 
                   - prefixSum[r2][c1-1] 
                   + prefixSum[r1-1][c1-1];

        cout << result << endl;
    }

    return 0;
}
