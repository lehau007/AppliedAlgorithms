
#include <limits>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

int n;

bool compareY(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

double d(vector<pair<int, int>>& ar, int a, int b) {
    int x = ar[a].first - ar[b].first;
    int y = ar[a].second - ar[b].second;
    return sqrt(x * x + y * y);
}

double closestPairTrip(vector<pair<int, int>> point, double delta) {
    return 0.0;
}

double solve(vector<pair<int, int>> &a, int start, int end, vector<pair<int, int>> &aY) {
    if (start == end - 1)
        return d(a, start, end);

    if (start == end)
        return MOD;

    int m = (start + end) / 2;

    double lm = solve(a, start, m - 1, aY);
    double rm = solve(a, m + 1, end, aY);

    double val = min(lm, rm); // like delta
    return 0.0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    vector<pair<int, int>> a_x(n);
    for (int i = 0; i < n; i++) {
        cin >> a_x[i].first >> a_x[i].second;
    }

    sort(a_x.begin(), a_x.end());
    double ans = MOD;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a_x[j].first - a_x[i].first >= ans) {
                break;
            }
            ans = min(ans, d(a_x, i, j));
        }
    }

    printf("%.6f", ans);

    return 0;
}
