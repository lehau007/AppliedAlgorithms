#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

/* 
call 0912345678 0132465789 2022-07-12 10:30:23 10:32:00
call 0912345678 0945324545 2022-07-13 11:30:10 11:35:11
call 0132465789 0945324545 2022-07-13 11:30:23 11:32:23
call 0945324545 0912345678 2022-07-13 07:30:23 07:48:30
#
?check_phone_number
?number_calls_from 0912345678
?number_total_calls
?count_time_calls_from 0912345678
?count_time_calls_from 0132465789
#
*/



int convert_time(char* time) {
    int hour, minute, second;
    sscanf(time, "%d:%d:%d", &hour, &minute, &second); 
    return hour * 3600 + minute * 60 + second;
}

bool checkNumber(string phonenumber) {
    if (phonenumber.size() != 10) 
        return false;
    for (char val : phonenumber) {
        if (val > '9' || val < '0') {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    map<string, pair<int, int>> store;
    bool check = true; int cnt = 0;

    string cmd; string from, to; char day[100], hourstart[100], hourend[100];

    while((cin >> cmd) && cmd != "#") {
        cin >> from >> to >> day >> hourstart >> hourend;
        if (!checkNumber(from) || !checkNumber(to)) {
            check = false;
            continue;
        } 
        
        cnt += 1;
        int start = convert_time(hourstart);
        int end = convert_time(hourend);
        store[from].first += 1;
        store[from].second += end - start;
    }

    while((cin >> cmd) && cmd != "#") {
        if (cmd == "?check_phone_number") {
            if (check) 
                cout << 1 << endl;
            else 
                cout << 0 << endl;
        } else if (cmd == "?number_calls_from") {
            cin >> from;
            cout << store[from].first << endl;
        } else if (cmd == "?number_total_calls") {
            cout << cnt << endl;
        } else if (cmd == "?count_time_calls_from") {
            cin >> from;
            cout << store[from].second << endl;
        }
    }
     
    return 0;
}