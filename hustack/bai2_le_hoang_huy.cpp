#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
/*
Bài 2 (P02). CỎ PHIẾU
Một nhà đầu tư tài chính quyết định đầu tư vào 2 nhóm cổ phiếu, nhóm cổ phiếu ngành công nghệ và nhóm cổ phiếu ngành bán lẻ.
Các mã cổ phiếu mà nhà đầu tư có thể lựa chọn đầu tư được đánh số từ 1 tới (n1 +n2)
trong đó các cổ phiếu ngành công nghệ có mã từ 1 tới n1, và các cổ phiếu ngành bán lẻ có mã từ (n1+1) tới (n1 + n2). Để giảm thiểu rủi ro tập trung,
nhà đầu tư đưa ra chiến lược như sau:
1.	Không đầu tư quá L mã cổ phiếu khác nhau;
2.	Mỗi nhóm cổ phiếu, không đầu tư quá M mã cổ phiếu khác nhau; Mỗi nhóm cổ phiếu, đầu tư ít nhất một mã cổ phiếu;
3.	Lập một danh sách gồm P cặp mã cổ phiếu không cùng đầu tư với nhau; mỗi cặp (u, v)
trong danh sách, nếu đầu tư vào mã cổ phiếu “ thì sẽ không đầu tư và mã cổ phiếu v; ngược lại nếu đầu tư vào mã cổ phiếu y thì sẽ không đầu tư vào mã cổ phiếu u vi 2 mã cố phiếu này có cùng chủ sở hữu.
Mỗi một chiến lược là một tập các mã cổ phiếu thỏa mãn các điều kiện trên, hỏi nhà đầu tư có bao nhiều chiến lược đầu tư khác nhau.
Dữ liệu vào:
• Dòng 1: Gồm 2 số nguyên cách nhau bởi dấu cách,
các giá trị này tương ứng với số lượng mã cổ phiếu trong mỗi nhóm (m, m), giá trị các số nguyên này nằm từ 1 tới 12;
Dòng 2: gồm 3 số nguyên, lần lượt là các giá trị L, M, I (L là số lượng tối đa nhà đầu tư lựa chọn, M là số cổ phiếu tối đa đầu tư vào 1 nhóm, I là số lượng cặp cổ phiếu không đầu tư cùng nhau)
P dòng kế tiếp: mỗi dòng gồm 2 số nguyên cách nhau, cặp mã cổ phiếu không đầu tư cùng nhau

Kết quả: 1 số nguyên dương là số chiến lượng đầu tư khác nhau
*/

using namespace std;

int n1, n2, n;
int L, M, P;
vector<vector<int>> cannot;
vector<vector<int>> memo;
vector<int> isselected;

int have_one = 0, have_two = 0;

bool isvalid(int cur) {
    if (cur < n1 && have_one == M)
        return false;

    if (cur >= n1 && have_two == M)
        return false;

    for (int j : cannot[cur]) {
        if (isselected[j] > 0) {
            return false;
        }
    }

    return true;
}

int backtracking(int idx, int cnt) {
    // if (memo[idx][cnt] != -1)
    //     return memo[idx][cnt];

    if (cnt <= L) {
        if (have_one > 0 && have_two > 0) {
            return 1;
        } else if (cnt == L) {
            return 0;
        }
    }

    if (idx == n) {
        return 0;
    }

    int ans = 0;
    if (isvalid(idx)) {
        isselected[idx] += 1;

        if (idx < n1) have_one += 1;
        if (idx >= n1) have_two += 1;

        ans += backtracking(idx + 1, cnt + 1);

        // Backtrack the flag changes
        if (idx < n1) have_one -= 1;
        if (idx >= n1) have_two -= 1;

        isselected[idx] -= 1;
    }

    ans += backtracking(idx + 1, cnt);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n1 >> n2; // <= 12
    n = n1 + n2;

    cin >> L >> M >> P;

    isselected.resize(n, 0);
    memo.resize(n, vector<int>(L + 1, -1));
    cannot.resize(n, vector<int>());
    int u, v;
    for (int i = 0; i < P; i++) {
        cin >> u >> v;
        u -= 1; v -= 1;

        cannot[u].push_back(v);
        cannot[v].push_back(u);
    }

    cout << backtracking(0, 0);

    return 0;
}
