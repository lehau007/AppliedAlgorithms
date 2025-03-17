#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<bool>> markR(9, vector<bool>(9, false)), markC(9, vector<bool>(9, false));
vector<vector<vector<bool>>> markS(9, vector<vector<bool>>(3, vector<bool>(3, false)));

vector<vector<int>> mat(9, vector<int>(9, 0));

void mark(int val, int r, int c) {
    val -= 1;
    markR[val][r] = true;
    markC[val][c] = true;
    markS[val][r / 3][c / 3] = true;
}

void rmark(int val, int r, int c) {
    val -= 1;
    markR[val][r] = false;
    markC[val][c] = false;
    markS[val][r / 3][c / 3] = false;
}

bool check(int val, int r, int c) {
    val -= 1;
    return (markR[val][r] || markC[val][c] || markS[val][r / 3][c / 3]);
}

int backtracking(int r, int c) {
    if (r == 9) {
        return 1;
    }

    if (c == 9) {
        return backtracking(r + 1, 0);
    } else if (mat[r][c] != 0) 
        return backtracking(r, c + 1);

    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        if (check(i, r, c))
            continue;
        mat[r][c] = i;
        mark(i, r, c);
        ans += backtracking(r, c + 1);
        rmark(i, r, c);
        mat[r][c] = 0;
    }
    // cout << "ans: " << ans << endl;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> mat[i][j];
            if (mat[i][j] != 0) {
                mark(mat[i][j], i, j);
            }
        }
    }

    cout << backtracking(0, 0);
    return 0;
}