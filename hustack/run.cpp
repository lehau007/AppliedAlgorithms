#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Anh thuong em, em thuong ai.

/*
Array a1, ..., an
print smallest number of cut such that all child-array in increasing order.
 test:
 6
 3 6 1 7 8 2
 answer: 3


 (3,6), (1,7,8), (2)
*/

int main(void) {
    // ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1])
            ans += 1;
    }

    cout << ans;

    return 0;
}

