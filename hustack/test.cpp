
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MOD = 1e9 + 7;

/*
Problem: Chapter 2. Count Solutions Vehicle Routing with K trucks and N orders
Description
Tại kho hàng (điểm 0), điều phối viên phải lập lộ trình vận chuyển hàng hóa cho K xe giống hệt nhau đi đến N khách hàng để giao hàng và quay về kho trung tâm. Biết rằng cả K xe đều phải giao hàng cho khách hàng và mỗi khách hàng chỉ được giao bởi đúng 1 xe. Thứ tự các điểm trên lộ trình là quan trọng, ví dụ lộ trình 0 - 1 - 2 - 0 và lộ trình 0 - 2 - 1 - 0 là 2 lộ trình khác nhau.
Với K = 2 và N = 3, ta có tất cả 6 phương án sau đây:
Phương án 1: xe 1 có lộ trình 0 - 1 - 0 và xe 2 có lộ trình 0 - 2 - 3 - 0
Phương án 2: xe 1 có lộ trình 0 - 1 - 0 và xe 2 có lộ trình 0 - 3 - 2 - 0
Phương án 3: xe 1 có lộ trình 0 - 2 - 0 và xe 2 có lộ trình 0 - 1 - 3 - 0
Phương án 4: xe 1 có lộ trình 0 - 2 - 0 và xe 2 có lộ trình 0 - 3 - 1 - 0
Phương án 5: xe 1 có lộ trình 0 - 3 - 0 và xe 2 có lộ trình 0 - 1 - 2 - 0
Phương án 6: xe 1 có lộ trình 0 - 3 - 0 và xe 2 có lộ trình 0 - 2 - 1 - 0
v
Hãy đếm số Q các phương án vận chuyển.

Input
Line 1: contains 2 positive integers N and K (1 <= N <= 100, 1 <= K <= 100).

Output
Write Q mod 100000

Example
Input
3 2

Output
6

*/
int k, n;

void solve() {
    if (n < k)
        return;

    long int ans = 1;
    for (int i = 2; i <= k; i++) {
        ans = (ans * i) % 100000;
    }

    for (int i = 0; i < n - k; i++) {
        ans = (ans * k) % 100000;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;

    solve();
    return 0;
}
