#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;

void backtracking(int k, string path, bool pre_is_one, bool two_pre) {
    if (k == n) {
        cout << path << endl;
        return;
    } 

    backtracking(k + 1, path + '0', false, pre_is_one);
    if (!pre_is_one || !two_pre)
        backtracking(k + 1, path + '1', true, pre_is_one);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    backtracking(0, "", false, false);
    return 0;
}