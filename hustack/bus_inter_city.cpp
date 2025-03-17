#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n;

void bfs(int src, vector<vector<int>>& adj_x, int count, vector<bool>& visited, vector<vector<int>> &adj) {
    if (count == 0)     
        return;
    queue<int> q;
    q.push(src);
    
    vector<int> steps(n + 1, 0);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        if (steps[cur] == count) 
            return;

        for (int val : adj_x[cur]) {
            if (!visited[val]) {
                adj[src].push_back(val);
                q.push(val);
                visited[val] = true;
                steps[val] = steps[cur] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m;
    cin >> n >> m;

    vector<int> C(n + 1), D(n + 1);
    vector<vector<int>> adj_x(n + 1); vector<bool> visited(n + 1, false);
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i]; 
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj_x[u].push_back(v);
        adj_x[v].push_back(u); 
    }

    // check all adj
    for (int i = 1; i < n + 1; i++) {
        visited[i] = true;
        
        bfs(i, adj_x, D[i], visited, adj);
    
        for (int val : adj[i]) {
            visited[val] = false;
        }
        visited[i] = false;
    }

    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;  

    priority_queue<pair<int, int>> pq;
    pq.push({-0, 1});

    while (!pq.empty()) {
        auto x = pq.top(); 
        pq.pop(); 

        if (x.second == n) {
            cout << dist[n]; 
            return 0;
        }

        for (int val : adj[x.second]) {
            int tmp = dist[x.second] + C[x.second];
            if (tmp < dist[val]) {
                dist[val] = tmp;
                pq.push({-tmp, val});
            }
        }
    }
    
    cout << -1 << endl;  
    return 0;
}
