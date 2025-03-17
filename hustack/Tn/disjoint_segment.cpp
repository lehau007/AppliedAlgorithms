
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

bool compareEnd(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> segment(n);
    for (int i = 0; i < n; i++) {
        cin >> segment[i].first >> segment[i].second;
    }

    sort(segment.begin(), segment.end(), compareEnd);

    int lastEnd = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (segment[i].first > lastEnd) {
            cnt += 1;
            lastEnd = segment[i].second;
        }
    }

    cout << cnt;
    return 0;
}
