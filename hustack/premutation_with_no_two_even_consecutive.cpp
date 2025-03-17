#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> visited;

void backtracking(int k, string path, int pre_even_val) {
    if (k == n) {
        cout << path << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            if (abs(i - pre_even_val) % 2 == 0) 
                continue;
        }
        if (visited[i - 1] == 0) {
            visited[i - 1] = 1;
            backtracking(k + 1, path + (char)(i + '0') + " ", i);
            visited[i - 1] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    visited.resize(n, 0);
    backtracking(0, "", 1);
    return 0;
}