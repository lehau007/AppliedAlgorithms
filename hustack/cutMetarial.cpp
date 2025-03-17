#include <iostream>
#include <vector>

using namespace std;

bool canFit(int H, int W, vector<pair<int, int>>& pieces, vector<vector<bool>>& used, int idx) {
    if (idx == pieces.size()) return true; 

    int h = pieces[idx].first, w = pieces[idx].second;

    for (int i = 0; i <= H - h; i++) {
        for (int j = 0; j <= W - w; j++) {
            // Check if can be placed
            bool fits = true;
            for (int x = i; x < i + h && fits; x++) {
                for (int y = j; y < j + w; y++) {
                    if (used[x][y]) {
                        fits = false;
                        break;
                    }
                }
            }

            if (fits) {
                // Mark 
                for (int x = i; x < i + h; x++) {
                    for (int y = j; y < j + w; y++) {
                        used[x][y] = true;
                    }
                }

                if (canFit(H, W, pieces, used, idx + 1)) {
                    return true;
                }

                // Backtrack
                for (int x = i; x < i + h; x++) {
                    for (int y = j; y < j + w; y++) {
                        used[x][y] = false;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int H, W;
    cin >> H >> W;
    int n;
    cin >> n;
    
    vector<pair<int, int>> pieces(n);
    for (int i = 0; i < n; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }

    vector<vector<bool>> used(H, vector<bool>(W, false));

    if (canFit(H, W, pieces, used, 0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}

