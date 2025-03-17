#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

/*
Description:

Có N điểm 1, 2, …, N cần thu gom bưu kiện và K bưu tá xuất phát từ bưu điện (điểm 0).
Biết d(i,j) là khoảng cách từ điểm i đến điểm j, với i,j = 0,1,..., N. Cần xây dựng phương án thu gom cho K bưu tá, xác định mỗi bưu tá thu gom nhưng điểm nào và theo thứ tự nào sao cho quãng đường dài nhất của bưu tá phải ngắn nhất.
Một phương án của bài toán là K lộ trình cho K xe, mỗi lộ trình k được biểu diễn bởi chuỗi lk số nguyên dương x[1], x[2], . . ., x[lk]  trong đó x[1] = 0 (điểm xuất phát, bưu điện), và x[2], x[3], . . , x[lk] là các điểm thu gom.
Input
Line 1: chứa 2 số nguyên dương N và K (1 <= N <= 1000, 1 <= K <= 100)
Line i+1 (i = 0,…,N): chứa dòng thứ i của ma trận khoảng cách d
Output
Line 1: chứa số nguyên dương K
Line 2*k (k = 1, . . ., K): chứa số nguyên dương lk
Line 2*k+1 (k = 1, . . ., K): chứa lk số nguyên x[1], x[2], . . . , x[lk] (các phần tử cách nhau bởi 1 ký tự SPACE)
*/


int n, k;
int size_n;
vector<vector<int>> mat;
vector<int> cars_cost;
vector<vector<int>> path;
vector<bool> visited;

/*
6 2
0 9 9 9 7 2 9
9 0 3 0 2 8 1
9 3 0 3 4 7 4
9 0 3 0 2 8 1
7 2 4 2 0 6 2
2 8 7 8 6 0 8
9 1 4 1 2 8 0
*/

void greedy(int cur_city) {
    // cout << cur_city << "hau\n";
    if (cur_city == size_n)
        return;

    int min_val = INT_MAX;
    int car_idx = -1;
    int new_idx = -1;
    for (int i = 1; i < size_n; i++) {
        if (visited[i])
            continue;

        for (int j = 0; j < k; j++) {
            int tmp = cars_cost[j] + mat[*(path[j].end() - 1)][i];
            if (tmp < min_val) {
                min_val = tmp;
                car_idx = j;
                new_idx = i;
            }
        }
    }

    path[car_idx].push_back(new_idx);
    visited[new_idx] = true;
    cars_cost[car_idx] = min_val;

    greedy(cur_city + 1);
}


int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    size_n = n + 1;
    mat.resize(size_n, vector<int>(size_n));

    cars_cost.resize(k, 0);
    path.resize(k, vector<int>(1, 0));
    visited.resize(size_n, false);

    for (int i = 0; i < size_n; i++) {
        for (int j = 0; j < size_n; j++) {
            cin >> mat[i][j];
        }
    }

    // Solve
    greedy(1);

    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << path[i].size() << endl;
        for (int val : path[i]) {
            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}
