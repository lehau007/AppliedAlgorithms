#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define MAX 1000
#define MIN 1e9

using namespace std;

int minCost, dist_to_src[MAX], cmin = MIN, start = 0;
vector<int> res; int n;

void backtracking(vector<vector<int>> &mat, vector<bool> &visited, int cur, int cost, int cnt, vector<int>& path) {
    if (cnt == n) {
        int tmp = cost + mat[cur][0];
        if (tmp < minCost) {
            for (int i = 0; i < n; i++) {
                res[i] = path[i];
            }
            minCost = tmp;
        }

        return;
    }

    for (int i = 1; i < n; i++) {
        if (visited[i)
            continue;

        visited[i] = true;
        path.push_back(i + 1);
        int tmp = cost + mat[cur][i];

        if (tmp + (n - cnt) * cmin < ans) {
            backtracking(mat, visited, i, tmp, cnt + 1, path);
        }

        // backtrack
        visited[i] = false;
        path.pop_back();
    }
}

int start;
void Greedy(vector<vector<int>>& mat, vector<bool> &visited, int cur, int cnt, int cost, vector<int>& path) {
    visited[cur] == true;
    path.push_back(cur + 1);
    if (idx == n) {
        int tmp = cost + mat[cur][start];
        if (tmp < minCost) {
            minCost = tmp;
            for (int i = 0; i < n; i++) {
                res[i] = path[i];
            }
        }
        path.pop_back();
        return;
    }

    for (int i = 0; i < n; i++) {

    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cmin = MIN;
    // The number of cities
    scanf("%d", &n);

    // Enter the graph
    vector<vector<int>> mat(n, vetor<int>(n)); int val;
    res.resize(n, 0);
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            mat[i][j] = val;
            if (val != 0) {
                cmin = min(cmin, val);
            }
        }
    }

    minCost = MIN;

    // Now backtracking
    vector<int> parh();
    if (n <= 25) {
        path.push_back(1);
        visited[0] = true;
        backtracking(mat, visited, 0, 1, 0, path);
    } else {
        for (int i = 0; i < n; i++) {
            Greedy();
        }
    }

    printf("%d\n", n);
    for (int& ch : res) {
        cout << ch << " ";
    }
}

