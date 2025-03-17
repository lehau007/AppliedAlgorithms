#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int m, n;
int preferences[10];
bool conflict[30][30];
int courseAssignment[30]; 
int load[10];
int ans = INF; 

bool isValid(int course, int teacher) {
    for (int i = 0; i < n; ++i) {
        if (courseAssignment[i] == teacher && conflict[course][i]) {
            return false;
        }
    }
    return true;
}

void backtracking(int course) {
    if (course == n) { 
        int curMaxLoad = *max_element(load, load + m);
        ans = min(ans, curMaxLoad);
        return;
    }

    for (int t = 0; t < m; ++t) {
        if (preferences[t] & (1 << course)) { 
            if (isValid(course, t)) { 
                courseAssignment[course] = t;
                load[t]++;

                if (load[t] < ans) {
                    backtracking(course + 1);
                }

                courseAssignment[course] = -1;
                load[t]--;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;

    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int mask = 0;
        for (int j = 0; j < k; ++j) {
            int course;
            cin >> course;
            mask |= (1 << (course - 1));  
        }
        preferences[i] = mask;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        conflict[a - 1][b - 1] = true;
        conflict[b - 1][a - 1] = true;
    }

    // Init()
    fill(courseAssignment, courseAssignment + n, -1);
    fill(load, load + m, 0);

    backtracking(0);

    if (ans == INF) {
        cout << -1 << endl;  
    } else {
        cout << ans << endl;  
    }

    return 0;
}
