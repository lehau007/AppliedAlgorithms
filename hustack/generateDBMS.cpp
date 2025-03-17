#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Anh thong em, em thuong ai

void add_string_with_one(string &str, int l) {
    for (int i = l - 1; i >= 1; i--) {
        int new_val = str[i] - '0' + 1;
        str[i] = (char)(new_val % 10 + '0');
        if (new_val != 10) {
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    /*
    map<string, bool> test;
    test["01"] = true;
    test["00"] = true;
    test["02"] = true;

    for (auto& x : test) {
        cout << x.first << " ";
    }

    return 1;
    */

    int n, l, m;
    cin >> n >> l >> m;

    map<string, bool> mp;

    string s;
    for (int i = 0; i < n; i++) {
       cin >> s;
       mp[s] = true;
    }

    string start = "";
    for (int i = 1; i < l; i++) {
        start += '0';
    }

    start += '1';
    for (int i = 0; i < m; i++) {
        while (mp[start]) {
            add_string_with_one(start, l);
        }

        mp[start] = true;
    }

    for (auto& x : mp) {
        cout << x.first << endl;
    }

    return 0;
}
