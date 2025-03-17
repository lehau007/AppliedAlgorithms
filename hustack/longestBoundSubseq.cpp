#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_len = -1;
    int left = 0, right = 0, sum = 0;

    while (right < n) {
        sum += a[right];
        while (sum > Q && left <= right) {
            sum -= a[left];
            left++;
        }
        if (sum <= Q) {
            max_len = max(max_len, right - left + 1);
        }
        right++;
    }

    cout << max_len << endl;
    return 0;
}
