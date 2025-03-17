#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

// Ta chi la nguoi xua, quan tam nhau lam gi nua

using namespace std;

vector<int> bags;
int n;

int ans = INT_MAX;
void solve(int a, int b, int k) {
    if (k == n) {
        int tmp = abs(a - b);
        ans = min(ans, tmp);
        return;
    }

    // First choice
    solve(a + bags[k], b, k + 1);
    solve(a, b + bags[k], k + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    bags.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    // Do
    solve(0, 0, 0);

    cout << ans;
    return 0;
}
