#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n;

void backtracking(int k, string path) {
    if (k == n) {
        cout << path << endl;
        return;
    } 

    backtracking(k + 1, path + '0');
    backtracking(k + 1, path + '1');
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    backtracking(0, "");
    return 0;
}