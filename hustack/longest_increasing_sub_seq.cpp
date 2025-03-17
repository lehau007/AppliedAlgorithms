#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Anh thương em nhiều lắm, nhưng em đâu nào hay.

const int MOD = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;

int findMaxLengthIncreasing(vector<int>& nums) {
    vector<int> sub;
    for (int num : nums) {
        auto it = lower_bound(sub.begin(), sub.end(), num);
        if (it == sub.end())
            sub.push_back(num);
        else
            *it = num;
    }
    return sub.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }
    cout << findMaxLengthIncreasing(sequence) << endl;
    return 0;
}

