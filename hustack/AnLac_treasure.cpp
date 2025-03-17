#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Treasure {
    long long x, y, c;
};

bool compare(const Treasure& a, const Treasure& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<Treasure> treasures(n);
    for (int i = 0; i < n; i++) {
        cin >> treasures[i].x >> treasures[i].y >> treasures[i].c;
    }

    sort(treasures.begin(), treasures.end(), compare);

    vector<long long> dp(n, 0);

    long long max_gold = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = treasures[i].c;
        for (int j = 0; j < i; j++) {
            if (treasures[j].x <= treasures[i].x && treasures[j].y <= treasures[i].y) {
                dp[i] = max(dp[i], dp[j] + treasures[i].c);
            }
        }
        max_gold = max(max_gold, dp[i]);
    }

    cout << max_gold << endl;

    return 0;
}
