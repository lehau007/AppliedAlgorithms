#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Anh thương em nhiều lắm, nhưng em đâu nào hay

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int k, n; cin >> k >> n;

    // need to find the nth string such that: dont't have 11
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    dp[1] = 2;
    int i = 0, j; long int total = 3;
    for (j = 2; j <= k; j++) {
        dp[j] = dp[j - 1] + dp[j - 2];
        total += dp[j];

        if (dp[j] > n) {
            if(j != k) {
                dp[j + 1] = dp[j] + dp[j - 1];
            }
            break;
        }

        if (total > n)
            i = j;
    }

    if (i == 0) {
        cout << -1;
    } else {
        string result = "";
        while (k > 0) {
            if (dp[k - 1] == 0) {
                result += '0';
                k -= 1;
            } else if (n <= dp[k - 1]) {
                result += '0';
                // cout << dp[k - 1] << "hau" << endl;
                k -= 1;
            } else {
                if (k >= 2)
                    result += "1";
                else
                    result += '1';
                n -= dp[k - 1];
                // cout << n << endl;
                k -= 1;
            }
        }
        cout << result;// << "size: " << result.size();
    }
    // 00000000100010000001010010010000101010000010101001

    return 0;
}
