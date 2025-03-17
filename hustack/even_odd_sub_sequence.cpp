#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

// Anh thuong em, em thuong ai

using namespace std;

int test_case;

bool comparator(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> test_case;
    while (test_case--) {
        int n; cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // cout << -155 % 2 << endl;

        vector<int> store_dp;
        // cout << *(store_dp.end() - 1);
        // return 0;

        // Case 1: odd first
        for (int i = 0; i < n; i++) {
            auto lb = lower_bound(store_dp.begin(), store_dp.end(), a[i], comparator);
            if (lb == store_dp.end()) {
                if (store_dp.size() == 0) {
                    if (a[i] % 2 == 1)
                        store_dp.push_back(a[i]);
                    continue;
                }
                if (abs((*(store_dp.end() - 1) + a[i]) % 2) == 1) {
                    store_dp.push_back(a[i]);
                }
            } else {
                if ((*lb + a[i]) % 2 == 0)
                    *lb = a[i];
            }
        }

        // Case 2: even first
        vector<int> store_dp_even_first;
        for (int i = 0; i < n; i++) {
            auto lb = lower_bound(store_dp_even_first.begin(), store_dp_even_first.end(), a[i], comparator);
            if (lb == store_dp_even_first.end()) {
                if (store_dp_even_first.size() == 0) {
                    if (a[i] % 2 == 0)
                        store_dp_even_first.push_back(a[i]);
                    continue;
                }
                if (abs((*(store_dp_even_first.end() - 1) + a[i]) % 2) == 1) {
                    store_dp_even_first.push_back(a[i]);
                }
            } else {
                if ((*lb + a[i]) % 2 == 0)
                    *lb = a[i];
            }
        }

        // for (int i : store_dp)
            // cout << i << " ";
        // cout << "end store" << endl;
        cout << max(store_dp.size(), store_dp_even_first.size()) << endl;
    }
    return 0;
}
