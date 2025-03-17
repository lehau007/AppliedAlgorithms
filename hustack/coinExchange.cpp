#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
typedef long long ll;
typedef unsigned long long ull;

/*
Description
Given a set of coins with denominations D1, D2, ..., Dn and a denomination x. Find the minimum number of coins to exchange for denomination x.
Input
Line 1: contains 2 positive integers n and x (1 <= n <= 1000, 1 <= x <= 1000)
Line 2: contains n positive integers D1, D2, . . ., Dn

Output
Write the minimum number of coins used

Example
Input
4 10
2 1 1 3
Output
4

*/

vector<vector<int>> memo(1001, vector<int>(1001));
int n; int m;
vector<int> A;

int dp(int idx, int cost, int cnt) {
    if (cost == 0) {
        memo[idx][cost] = cnt;
        return cnt;
    } else if (cost < 0) {
        return MOD;
    }

    if (idx == n) {
        return MOD;
    }

    if (memo[idx][cost] != 0)
        return memo[idx][cost];

    int res = MOD;
    res = min(res, dp(idx + 1, cost, cnt));
    res = min(res, dp(idx, cost - A[idx], cnt + 1));

    memo[idx][cost] = res;
    return res;
}

void input(){
    cin >> n; cin >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        A.push_back(x);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    input();

    cout << dp(0, m, 0);
    return 0;
}
