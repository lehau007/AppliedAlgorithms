#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    sort(d.begin(), d.end(), compare);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, d[i] + i);
    }

    cout << ans;
    return 0;
}