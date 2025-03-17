#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> visited;

void backtracking(int k, string path) {
    if (k == n) {
        cout << path << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (visited[i - 1] == 0) {
            visited[i - 1] = 1;
            backtracking(k + 1, path + (char)(i + '0') + " ");
            visited[i - 1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    visited.resize(n, 0);
    backtracking(0, "");
    return 0;
}