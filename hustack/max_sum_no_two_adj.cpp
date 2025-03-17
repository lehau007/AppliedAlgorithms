/*
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        dp = [0] * n

        # init()
        dp[0] = nums[0]
        if n > 1:
            dp[1] = nums[1]

        if n >= 3:
            dp[2] = max(dp[0] + nums[2], dp[1])

        for i in range(3, n):
            j = i - 2
            k = i - 3

            dp[i] = nums[i] + max(dp[j], dp[k])

        return max(dp[n - 1], dp[n - 2])
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;

int n; int m;
vector<int> a;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        a.push_back(val);
    }

    // Solution:
    vector<int> dp(n, 0);
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = max(a[2], a[2] + a[0]);

    int ans = max(a[0], a[1]);
    ans = max(ans, dp[2]);

    for (int i = 3; i < n; i++) {
        dp[i] = max(max(dp[i - 2], dp[i - 3]), 0) + a[i];
        ans = max(ans, dp[i]);
    }

    cout << ans;
    return 0;
}
