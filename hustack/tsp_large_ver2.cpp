#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define MAX 1000
#define MIN 1e9

using namespace std;

struct Pair {
    int real_idx;
    int val;
};

int minCost, dist_to_src[MAX], dem = 0, cmin = MIN;
vector<int> res;

bool compare(const Pair &a, const Pair &b) {
    return a.val < b.val;
}

void Backtracking(vector<vector<Pair>>& matrix, int src, vector<int>& visited, int sum, int n, int idx, vector<int>& temp) {
    // printf("%d, %d : %d\n", idx, src, sum);
    for (int i = 1; i < n; i++) {
        int real_idx = matrix[src][i].real_idx;
        if (visited[real_idx] == 1)
            continue;

        int tmp = sum + matrix[src][i].val;
        if (tmp + cmin * (n - idx) >= minCost)
            return;

        visited[real_idx] = 1;
        temp[idx + 1] = real_idx + 1;

        if (idx == n - 2) {
            // printf("%d \n", tmp);
            if (minCost > tmp + dist_to_src[real_idx]) {
                minCost = tmp + dist_to_src[real_idx];
                res = temp;
            }
        } else
            Backtracking(matrix, real_idx, visited, tmp, n, idx + 1, temp);

        // Return
        visited[real_idx] = 0;
    }
}

int start = 0;
void Greedy(vector<vector<Pair>>& matrix, int cur, vector<int>& visited, int n, int idx, vector<int>& temp, int cost) {
    temp[idx] = cur + 1;
    if (idx == n - 1) {
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            if (matrix[cur][i].real_idx == start) {
                tmp = matrix[cur][i].val;
            }
        }

        if (cost + tmp < minCost) {
            minCost = cost + tmp;
            res = temp;
        }
        return;
    }

    for (int i = 1; i < n; i++) {
        if (visited[matrix[cur][i].real_idx] == 0) {
            visited[matrix[cur][i].real_idx] = 1;

            Greedy(matrix, matrix[cur][i].real_idx, visited, n, idx + 1, temp, cost + matrix[cur][i].val);
            visited[matrix[cur][i].real_idx] = 0;
            return;
        }
    }
}

int main() {
    cmin = MIN; dem = 0;
    int n; // The number of cities
    scanf("%d", &n);

    // Enter the graph
    vector<vector<Pair>> matrix(n, vector<Pair>(n));
    vector<int> visited(n);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &(matrix[i][j].val));
            matrix[i][j].real_idx = j;
        }
        dist_to_src[i] = matrix[i][0].val;
        // Sort
        sort(matrix[i].begin(), matrix[i].end(), compare);
        if (matrix[i][1].val < cmin)
            cmin = matrix[i][1].val;
    }

    minCost = MIN;

    vector<int> temp(n);
    temp[0] = 1;
    // Now backtracking

    if (n <= 30) {
        visited[0] = 1;
        Backtracking(matrix, 0, visited, 0, n, 0, temp);
    } else {
        for (int i = 0; i < n; i++) {
            start = i;
            visited[start] = 1;
            Greedy(matrix, start, visited, n, 0, temp, 0);
            visited[start] = 0;
        }
    }

    printf("%d\n", n);
    for (int& ch : res) {
        cout << ch << " ";
    }

    return 0;
}

