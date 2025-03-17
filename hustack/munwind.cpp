
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

int n;
vector<bool> visited;
void backtracking(int i, string path) {
    if (i == n) {
        for (char ch : path) {
            cout << ch << " ";
        }
        cout << endl;
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = true;
            char val = j + '0';
            backtracking(i + 1, path + val);
            visited[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    visited.resize(n + 1, false);
    backtracking(0, "");
    return 0;
}
