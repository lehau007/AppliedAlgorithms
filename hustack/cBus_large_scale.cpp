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

int n, k, m, cmin = MOD, min_cost = MOD;
vector<vector<int>> mat; vector<bool> visited;
// load cur val for the number of people in bus
vector<int> res;

void backtracking(int cur, int cnt, vector<int>& path, int cost, int load) {
    if (cnt == m) {
        int tmp = cost + mat[cur][0];
        if (tmp < min_cost) {
            // copy path
            for (int i = 0; i < m - 1; i++) {
                res[i] = path[i];
                // cout << path[i] << " ";
            }

            // cout << "End turn\n";
            min_cost = tmp;
        }
        return;
    }

    if (load < k) {
        // try to pick
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = true; // pick success;
                int tmp = cost + mat[cur][i];
                path.push_back(i);

                if (tmp + (m - cnt) * cmin < min_cost) {
                    backtracking(i, cnt + 1, path, tmp, load + 1);
                }

                // backtrack
                visited[i] = false;
                path.pop_back();
            }
        }
    }

    if (load > 0) {
        // try to drop-off
        for (int i = n + 1; i < m; i++) {
            if (!visited[i] && visited[i - n]) { // passeger haven't been deliver and currently in bus
                visited[i] = true; // drop-off successfully;
                int tmp = cost + mat[cur][i];
                path.push_back(i);

                if (tmp + (m - cnt) * cmin < min_cost) {
                    backtracking(i, cnt + 1, path, tmp, load - 1);
                }

                // backtrack
                visited[i] = false;
                path.pop_back();
            }
        }
    }
}

int cost = 0;
void Greedy(int cur, int cnt, vector<int>& path, int load) {
    if (cnt == m) {
        cout << n << endl;
        for (int i = 0; i < m - 1; i++) {
            cout << path[i] << " ";
        }

        cout << endl << "cost is: " << cost + mat[cur][0];

        return;
    }

    //cout << cur << " in line: "<< cnt <<endl;
    int nearest = MOD, idx_near = -1;
    for (int i = 1; i < m; i++) {
        if (visited[i])
            continue;

        if (i > n && !visited[i - n])
            continue;

        if (load == k && i <= n)
            continue;

        int tmp = mat[cur][i];
        if (tmp < nearest) {
            // update near
            nearest = tmp;
            idx_near = i;
        }
    }

    path.push_back(idx_near);
    cost += mat[cur][idx_near];
    visited[idx_near] = true;
    if (idx_near <= n)
        load += 1;
    else
        load -= 1;
    Greedy(idx_near, cnt + 1, path, load);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    m = 2 * n + 1;

    mat.resize(m, vector<int>(m, 0));
    visited.resize(m, false);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != 0) {
                cmin = min(cmin, mat[i][j]);
            }
        }
    }

    visited[0] = true;
    vector<int> path;
    if (n <= 10) {
        res.resize(2 * n, 0);
        backtracking(0, 1, path, 0, 0);
        cout << n << endl;
        for (int i = 0; i < 2 * n; i++) {
            cout << res[i] << " ";
        }
    } else {
        Greedy(0, 1, path, 0);
    }

    return 0;
}
