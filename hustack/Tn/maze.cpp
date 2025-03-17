#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct position {
    int r, c;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, n, r, c; cin >> m >> n >> r >> c;
    r -= 1; c -= 1;
    
    vector<vector<int>> mat(m, vector<int>(n)), steps(m, vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    queue<position> q;
    position cur = {r, c};
    mat[r][c] = 1;
    q.push(cur);

    vector<vector<int>> directs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur.r == 0 || cur.r == m - 1 || cur.c == 0 or cur.c == n - 1) {
            cout << steps[cur.r][cur.c] + 1;
            return 0;
        }
        
        for (auto d : directs) {
            position neighbor = {cur.r + d[0], cur.c + d[1]};
            if ((neighbor.r >= 0 && neighbor.r < m) && (neighbor.r >= 0 && neighbor.c < n)) {
                if (mat[neighbor.r][neighbor.c] == 0) {
                    steps[neighbor.r][neighbor.c] = steps[cur.r][cur.c] + 1;
                    mat[neighbor.r][neighbor.c] = 1;
                    q.push(neighbor);
                }
            }
        }
    }
    cout << "-1";
    return 0;
}