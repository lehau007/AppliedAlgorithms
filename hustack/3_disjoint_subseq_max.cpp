#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Anh thuong em, em thuong ai.

/*
Description
Given a sequence of n integers a[1], a[2], . . ., a[n]. A subsequence is defined to be a sequence of consecutive elements a[i], a[i+1], . . ., a[j].
Find 3 subsequences of the given sequence such that the sum of elements of these 3 subsequences is maximal.
Input
Line 1: contains a positive integers n (5 <= n <= 10000)
Line 2: contains a[1], a[2], . . ., a[n] (-1000 <= a[i] <= 1000)

Output
Write the sum of elements of the 3 subsequences found.

Example
Input
8
3 2 -8 4 5 -10 6 13

Output
33
*/

#define int long long

int n;
vector<int> a;

signed main() {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Dynamic solution
    vector<int> max_left(n), dp_right(n, 0);
    vector<int> max_right(n), dp_left(n, 0);

    dp_left[0] = a[0]; dp_right[n - 1] = a[n - 1];
    max_left[0] = a[0]; max_right[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) {
        dp_left[i] = max(a[i], dp_left[i - 1] + a[i]);
        max_left[i] = max(max_left[i - 1], dp_left[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        dp_right[i] = max(a[i], dp_right[i + 1] + a[i]);
        max_right[i] = max(max_right[i + 1], dp_right[i]);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int sum = 0;
        for (int j = i; j < n - 1; j++) {
            sum += a[j];
            ans = max(ans, max_left[i - 1] + max_right[j + 1] + sum);
        }
    }

    cout << ans;
    return 0;
}
