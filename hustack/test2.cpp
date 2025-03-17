#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Segment;

bool compareByEnd(const Segment& s1, const Segment& s2) {
    return s1.second < s2.second;
}

int main() {
    int n;
    cin >> n;

    vector<Segment> segments(n);

    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }

    sort(segments.begin(), segments.end(), compareByEnd);

    int count = 0;
    int lastEnd = -1;

    for (int i = 0; i < n; ++i) {
        if (segments[i].first > lastEnd) {
            count++;
            lastEnd = segments[i].second;
        }
    }

    cout << count << endl;

    return 0;
}
