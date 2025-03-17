#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Anh thuong em, em thuong ai.

int n, m;
vector<vector<int>> teachers;
vector<int> credits;
vector<int> minCourses;
vector<vector<int>> conflict;
vector<int> chooseTeachers;
vector<int> load;

int ans = INT_MAX;

bool isValid(int course, int teacher) {
    for (int val : conflict[course]) {
        if (chooseTeachers[val] == teacher)
            return false;
    }

    return true;
}
void backtracking(int course) {
    if (course == n) {
        for (int i = 0; i < m; i++) {
            if (minCourses[i] > 0)
                return;
        }

        int min_val;
        for (int i = 0; i < m; i++) {
            if (load[i] < min_val)
                min_val = load[i];
        }

        ans = min(ans, min_val);
    }
    for (int teacher : teachers[course]) {
        if (isValid(course, teacher)) {
            load[teacher] += credits[course];
            if (load[teacher] >= ans) {
                load[teacher] -= credits[course];
                continue;
            }
            chooseTeachers[course] = teacher;
            minCourses[teacher] -= 1;
            backtracking(course + 1);

            // remain value
            load[teacher] -= credits[course];
            chooseTeachers[course] = -1;
            minCourses[teacher] += 1;
        }
    }
}

int main() {
    cin >> n >> m;

    teachers.resize(n);
    credits.resize(n);
    minCourses.resize(m);
    conflict.resize(n);
    chooseTeachers.resize(n, -1);
    load.resize(m, 0);
    for (int i = 0; i < m; i++) {
        int p; cin >> p;
        for (int j = 0; j < p; j++) {
            int course; cin >> course; course -= 1;
            teachers[course].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> credits[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> minCourses[i];
    }

    int p; cin >> p;
    for (int i = 0; i < p; i++) {
        int u; int v;
        u -= 1; v -= 1;

        conflict[u].push_back(v);
        conflict[v].push_back(u);
    }

    backtracking(0);
    cout << ans;
    return 0;
}
