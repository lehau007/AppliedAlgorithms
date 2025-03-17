#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int csize, asize, bsize;
string a, b, c;
bool solve(int idx, int l_a, int l_b) {
    if (idx == csize)
        return true;

    if (l_b == bsize)
        return false;

    if (l_a == asize)
        return false;

    // Finding in a
    int new_la = asize - 1;
    for (int i = l_a; i < asize; i++) {
        if (a[i] == c[idx]) {
            new_la = i;
            break;
        }
    }

    if (solve(idx + 1, new_la + 1, l_b))
        return true;

    // Finding in b
    int new_lb = bsize - 1;
    for (int i = l_b; i < bsize; i++) {
        if (b[i] == c[idx]) {
            new_lb = i;
            break;
        }
    }

    if (solve(idx + 1, l_a, new_lb + 1))
        return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b >> c;

    if (solve(0, 0, 0))
        cout << "T";
    else
        cout << "F";
    return 0;
}
