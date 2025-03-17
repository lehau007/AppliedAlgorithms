#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

// Anh thương em nhiều lắm, nhưng em đâu nào hay.

const int MOD = 1e9 + 7;

int n; long int ans = - (long int)MOD;
long int* a;
long int evenDp, oddDp; bool preHasEven = false, preHasOdd = false; long int cur_evenDp = 0, cur_oddDp = 0; bool hasEven = false, hasOdd = false;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    a = (long int*)malloc(n * sizeof(long int));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Solution with dynamic programming
    if (a[0] % 2 == 0) {
        hasEven = true;
        ans = max(a[0], ans);
        cur_evenDp = a[0];
    } else {
        hasOdd = true;
        cur_oddDp = a[0];
    }

    for (int i = 1; i < n; i++) {
        preHasEven = hasEven; preHasOdd = hasOdd;
        evenDp = cur_evenDp; oddDp = cur_oddDp;

        if (a[i] % 2 == 0) {
            if (preHasEven) {
                cur_evenDp = max(a[i], evenDp + a[i]);
            } else {
                cur_evenDp = a[i];
            }
            hasEven = true;
            ans = max(ans, cur_evenDp);

            if (preHasOdd) {
                hasOdd = true;
                cur_oddDp = (a[i] + oddDp);
            } else {
                hasOdd = false;
            }
        } else {
            if (preHasOdd) {
                hasEven = true;
                cur_evenDp = (a[i] + oddDp);
                ans = max(ans, cur_evenDp);
            } else {
                hasEven = false;
            }

            if (preHasEven) {
                cur_oddDp = max(a[i], evenDp + a[i]);
            } else {
                cur_oddDp = a[i];
            }
            hasOdd = true;
        }
    }

    cout << ans;

    free(a);
    return 0;
}
