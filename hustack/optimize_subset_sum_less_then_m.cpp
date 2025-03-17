#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

// Ta chi la nguoi xua, quan tam nhau lam gi nua

using namespace std;

vector<int> bags;
int n;

int ans = INT_MIN, m;
void solve(int sum, int k) {
    if (sum > m)
        return;

    if (k == n) {
        ans = max(ans, sum);
        return;
    }

    // First choice
    solve(sum + bags[k], k + 1);
    solve(sum, k + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;

    bags.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    cin >> m;

    // Do
    solve(0, 0);

    cout << m - ans;
    return 0;
}
