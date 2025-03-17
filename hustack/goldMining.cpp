#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Anh thuong em, em thuong ai

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

int n, l1, l2;
vector<int> a;
vector<int> Tree;

void buildTree(int l, int r, int id) {
    if (l == r) {
        Tree[id] = a[l];
        return;
    }

    int m = (l + r) / 2;
    int child1 = 2 * id + 1, child2 = 2 * id + 2;
    buildTree(l, m, child1);
    buildTree(m + 1, r, child2);

    Tree[id] = max(Tree[child1], Tree[child2]);
}

void insertTree(int l, int r, int id, int idx, int value) {
    if (l == r) {
        Tree[id] = value;
        return;
    }

    int m = (l + r) / 2;
    if (idx <= m) {
        insertTree(l, m, 2 * id + 1, idx, value);
    } else {
        insertTree(m + 1, r, 2 * id + 2, idx, value);
    }

    Tree[id] = max(Tree[2 * id + 1], Tree[2 * id + 2]);
}

int find_max(int l, int r, int start, int target, int id) {
    // out of range, fully in range and other
    if (r < start || l > target)
        return INT_MIN;
    if (l >= start && r <= target)
        return Tree[id];

    int m = (l + r) / 2;
    int left = find_max(l, m, start, target, 2 * id + 1);
    int right = find_max(m + 1, r, start, target, 2 * id + 2);

    return max(left, right);
}

int find_for_dp(int l, int r) {
    if (l > r) // Exception
        return INT_MIN;
    if (l < 0 && r < 0)
        return INT_MIN;
    else
        l = max(l, 0);
    return find_max(0, n - 1, l, r, 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> l1 >> l2;
    a.resize(n);
    Tree.resize(4 * n, INT_MIN);
    int cur_dp = INT_MIN;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {

        cur_dp = INT_MIN;
        cur_dp = max(cur_dp, find_for_dp(i - l2, i - l1));

        cur_dp = max(a[i], a[i] + cur_dp);

        insertTree(0, n - 1, 0, i, cur_dp);
        ans = max(ans, cur_dp);
    }

    cout << ans;

    return 0;
}
