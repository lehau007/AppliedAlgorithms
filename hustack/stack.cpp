#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> stack;

    while (1) {
        string command; int val;
        cin >> command;
        if (command == "#") 
            break;
        
        if (command == "PUSH") {
            cin >> val;
            stack.push_back(val);
        } else if (command == "POP") {
            if (stack.size() == 0) {
                cout << "NULL" << endl;
            } else {
                cout << stack[stack.size() - 1] << endl;
                stack.pop_back();
            }
        }
    }
    return 0;
}
    