#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Anh thuong em, em thuong ai.

// Problem details:

/*
An engineer needs to schedule a machine to run on some given periods 1,…,n
 to produce a chemical product C
. Each period i
 is represented by a starting time point si
 and terminating time point ti
 (si<ti
). Due to a technical constraint, the machine must run on exactly two periods that are not overlap (two periods i
 and j
 are not overlap if ti<sj
 or tj<si
). If the machine is runned on the period i
, then the amount of C
 it will produce is equal to the duration of the period i
 (which is equal to ti−si
). Help the engineer to select two not-overlap periods to run the machine such that the amount of C
 produced is maximal.

Input
Line 1: contains the positive integer n
 (2≤n≤2⋅106
)
Line i+1
: contains two positive integer si
 and ti
 (1≤si<ti≤2⋅106
)
Output
The output consists of only one single integer which is the amount of product C
the machine will produce in the two selected periods. In case there is no solution (there does not
exist two periods that are not overlap), the output contains the value -1.
*/

vector<int> segmentTree;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> periods; // first is start and second is terminating time
    for (int i = 0; i < n; i++) {
        int s, t; cin >> s >> t;
        periods.push_back({s, t});
    }

    sort(periods.begin(), periods.end(), compare);

    int ans = -1, cur_max = periods[0].second - periods[0].first;
    for (int i = 1; i < n; i++) {
        if (periods[i].first > periods[i - 1].second) {
            int tmp = periods[i].second - periods[i].first;
            ans = max(ans, cur_max + tmp);
            cur_max = max(cur_max, tmp);
        }
    }

    return 0;
}
