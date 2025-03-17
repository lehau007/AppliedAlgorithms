#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Canh em da co ai kia, ngay ngay nam doi tay. Va` nguoi lam` cho giac mo nay` them vun vo

//  Balanced Academic Curriculum Problem

/*
Description
The BACP is to design a balanced academic curriculum by assigning periods to courses in a way that the academic load of each period is balanced. There are N courses 1, 2, …, N that must be assigned to M periods 1, 2, …, M. Each course i has credit ci and has some courses as prerequisites. The load of a period is defined to be the sum of credits of courses assigned to that period.
The prerequisites information is represented by a matrix ANxN in which Ai,j = 1 indicates that course i must be assigned to a period before the period to which the course j is assigned. Compute the solution satisfying constraints: 
Satisfy the prerequisites constraints: if Ai,j = 1, then course i must be
assigned to a period before the period to which the course j is assigned
The maximum load for all periods is minimal

Input
Line 1 contains N and M (2 ≤ N ≤16, 2 ≤ M ≤ 5)
Line 2 contains c1, c2, …, cN
Line i+2 (i = 1,…, N) contains the ith line of the matrix A

Output
Unique line contains that maximum load for all periods of the solution
found
Example
Input
6 2
4 4 4 4 2 4 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 0 0 0 0 
0 0 1 0 0 0 
0 0 1 0 0 0 
1 0 0 0 0 0

Output
12
*/

int n, m;
vector<int> credits;
vector<vector<int>> adj;  // graph with form is adj list
vector<int> in_degree;    // degree of nodes
vector<vector<int>> need(20);

vector<int> topological_sort() {
    vector<int> topo_order;
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        
        for (int v : adj[u]) {
            --in_degree[v];
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topo_order;
}

bool can_assign(int course, int se, vector<int>& assignment) {
    for (int pre : need[course]) {
        if (assignment[pre] >= se) 
            return false;
    }
    
    return true;
}

void backtracking(int idx, vector<int>& topo_order, vector<int>& period_load, vector<int>& assignment, int& ans, int cur_max_load) {
    if (idx == n) {
        ans = min(ans, cur_max_load);
        return;
    }

    int course = topo_order[idx];
    for (int p = 0; p < m; ++p) {
        if (can_assign(idx, p, assignment)) {
            period_load[p] += credits[course];  // Add the course credit 
            assignment[course] = p;            

            if (period_load[p] < ans)
                backtracking(idx + 1, topo_order, period_load, assignment, ans, max(cur_max_load, period_load[p]));

            // undo
            period_load[p] -= credits[course];
            assignment[course] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    credits.resize(n);
    adj.resize(n);
    in_degree.resize(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> credits[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int pre;
            cin >> pre;
            if (pre == 1) {
                adj[i].push_back(j);  
                need[j].push_back(i);
                in_degree[j]++;
            }
        }
    }

    vector<int> topo_order = topological_sort();

    vector<int> period_load(m, 0);    
    vector<int> assignment(n, -1);    
    int ans = INT_MAX;     

    backtracking(0, topo_order, period_load, assignment, ans, 0);

    cout << ans << endl;

    return 0;
}
