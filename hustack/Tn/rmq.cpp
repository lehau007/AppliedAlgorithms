#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <climits>

using namespace std;

int *tree, *ar; int n;

void buildTree(int id, int start, int end) {
    if (start > end)
        return;

    if (start == end) {
        tree[id] = ar[start];
    }

    int mid = start + (end - start) / 2;
    int idleft = 2 * id, idright = idleft + 1;
    buildTree(idleft, start, mid);
    buildTree(idright, mid + 1, end);
    
    tree[id] = min(tree[idleft], tree[idright]);
}

int rmq(int id, int start, int end, int left, int right) {
    if (right < start || left > end) 
        return INT_MAX;

    if (left >= start && right <= end) 
        return tree[id];

    int mid = (right - left) / 2 + left;
    int left_val = rmq(id * 2, left, mid, start, end);
    int right_val = rmq(id * 2 + 1, mid + 1, right, start, end);

    return min(left_val, right_val);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    tree = (int*)malloc(4 * n * sizeof(int));
    ar = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    
    buildTree(1, 0, n - 1);
    int t; cin >> t; int ans = 0;
    while (t--) {
        int left, right;
        cin >> left >> right;
        ans += rmq(1, 0, n - 1, left, right);
    }
    cout << ans;
    
    free(tree); free(ar);
    return 0;
}