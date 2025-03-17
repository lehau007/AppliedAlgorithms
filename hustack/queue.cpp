#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    queue<int> q;

    while (1) {
        string command; int val;
        cin >> command;
        if (command == "#") 
            break;
        
        if (command == "PUSH") {
            cin >> val;
            q.push(val);
        } else if (command == "POP") {
            if (q.empty()) {
                cout << "NULL" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
    return 0;
}
    