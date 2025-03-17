#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

// Anh thuong em, em thuong ai

int n; int ans = 0;

void merge(vector<int>& ar, int l, int m, int r) {
    int len = r - l + 1;
    int tmp[len];

    int idxa = l, idxb = m + 1;
    for (int i = 0; i < len; i++) {
        if (idxa <= m &&  idxb <= r) {
            if (ar[idxa] > ar[idxb]) {
                ans += m - idxa + 1;
                ans = ans % MOD;
                tmp[i] = ar[idxb];
                idxb += 1;
            } else {
                tmp[i] = ar[idxa];
                idxa += 1;
            }
        } else if (idxa <= m) {
            tmp[i] = ar[idxa];
            idxa += 1;
        } else {
            tmp[i] = ar[idxb];
            idxb += 1;
        }
    }

    // remainning
    for (int i = 0; i < len; i++) {
        ar[i + l] = tmp[i];
    }
}

void mergesort(vector<int> &ar, int l, int r) {
    if (l == r)
        return;

    int m = (l + r) / 2;
    mergesort(ar, l, m);
    mergesort(ar, m + 1, r);

    merge(ar, l, m, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    mergesort(ar, 0, n - 1);

    cout << ans % MOD;
    return 0;
}
