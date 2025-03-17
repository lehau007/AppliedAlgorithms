#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, val;
    cin >> n;

    vector<int> preffix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> val;
        preffix[i] = preffix[i - 1] + val;
    }

    int Query;
    cin >> Query;

    while (Query--) {
        int l, r;
        cin >> l >> r;

        cout << preffix[r] - preffix[l - 1] << endl;
    }

    return 0;
}
