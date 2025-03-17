#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

// n is number of customers, K number of trucks, Q is capacity, d[i] is the demand of customer i
// c[i][j] is the distance from i to j
int n, K, Q;
int *y, *x, *load, *d, **c, Cmin = INT_MAX;
bool *visited;

int f, fmin = INT_MAX, segments, nbR;

void updateBest() {
    fmin = min(fmin, f);
}

bool checkX(int v, int k) {
    if (v > 0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

void TRY_X(int s, int k) {  // Try assigning customer `s` to truck `k`
    if (s == 0) { // All customers have been assigned, try next truck
        if (k < K) TRY_X(y[k + 1], k + 1);
        return;
    }

    for (int v = 0; v <= n; v++) {
        if (checkX(v, k)) {
            x[s] = v;
            visited[v] = true;
            f += c[s][v];
            load[k] += d[v];
            segments++;

            if (v > 0) {  // Assign another customer if there are still more to go
                if (f + (n + nbR - segments) * Cmin < fmin)
                    TRY_X(v, k);
            } else {
                if (k == K) {
                    if (segments == n + nbR) 
                        updateBest();
                } else {
                    if (f + (n + nbR - segments) * Cmin < fmin)
                        TRY_X(y[k + 1], k + 1);
                }
            }

            // Backtrack
            visited[v] = false;
            f -= c[s][v];
            load[k] -= d[v];
            segments--;
        }
    }
}

bool checkY(int v, int k) {
    if (v == 0) return true;
    if (load[k] + d[v] > Q) return false;
    if (visited[v]) return false;
    return true;
}

void TRY_Y(int k) {  // Try assigning truck `k` to a customer
    int s = (y[k - 1] > 0) ? y[k - 1] + 1 : 0;
    
    for (int v = s; v <= n; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0) segments++;
            visited[v] = true;
            f += c[0][v];
            load[k] += d[v];

            if (k < K) 
                TRY_Y(k + 1);
            else {
                nbR = segments;
                TRY_X(y[1], 1);
            }

            // Backtrack
            load[k] -= d[v];
            visited[v] = false;
            f -= c[0][v];
            if (v > 0) segments--;
        }
    }
}

void solve() {
    f = 0;
    fmin = INT_MAX;
    segments = 0;
    y[0] = 0;

    memset(visited, false, (n + 1) * sizeof(bool));

    TRY_Y(1);  
    cout << fmin << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> K >> Q;

    y = new int[n + 1];
    x = new int[n + 1];
    load = new int[K + 1];
    d = new int[n + 1];
    visited = new bool[n + 1];
    c = new int*[n + 1];

    // Initialize load, y, and x
    for (int i = 0; i <= K; i++) {
        load[i] = 0;
        y[i] = 0;
        x[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    d[0] = 0;

    for (int i = 0; i <= n; i++) {
        c[i] = new int[n + 1];
        for (int j = 0; j <= n; j++) {
            cin >> c[i][j];
            if (c[i][j] != 0) Cmin = min(Cmin, c[i][j]);
        }
    }

    // Solve the problem
    solve();

    // Free memory
    delete[] y;
    delete[] x;
    delete[] d;
    delete[] visited;
    delete[] load;
    for (int i = 0; i <= n; i++) {
        delete[] c[i];
    }
    delete[] c;

    return 0;
}
