#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;

int max_e; int sum = 0;

// Hàm kiểm tra tính khả thi khi tổng của mỗi mảng con không vượt quá maxSum
bool canPartition(const vector<int>& arr, int k, int maxSum) {
    int currentSum = 0;
    int subarrayCount = 1; // Bắt đầu với mảng con đầu tiên

    for (int num : arr) {
        // Nếu cộng thêm num mà vượt maxSum thì cần tạo một mảng con mới
        if (currentSum + num > maxSum) {
            subarrayCount++;
            currentSum = num;
            // Nếu số mảng con vượt quá k, không khả thi
            if (subarrayCount > k) return false;
        } else {
            currentSum += num;
        }
    }

    return true;
}

// Hàm tìm giá trị nhỏ nhất của maxSum - minSum
int minimizeMaxSum(const vector<int>& arr, int k) {
    int low = max_e; // Giá trị lớn nhất trong mảng
    int high = sum;
    int result = high;

    // Nhị phân trên khoảng giá trị của maxSum
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Kiểm tra nếu có thể chia mảng với maxSum là mid
        if (canPartition(arr, k, mid)) {
            result = mid; // Cập nhật kết quả
            high = mid - 1; // Tiếp tục tìm giá trị nhỏ hơn
        } else {
            low = mid + 1; // Tăng ngưỡng maxSum
        }
    }

    int currentSum = 0;
    int min_val = INT_MAX;

    for (int num : arr) {
        // Nếu cộng thêm num mà vượt maxSum thì cần tạo một mảng con mới
        if (currentSum + num > result) {
            min_val = min(currentSum, min_val);
            currentSum = num;
        } else {
            currentSum += num;
        }
    }

    return result - min_val;
}

bool check(vector<int>& arr, int k, int min_val) {
    int cnt = 1; int current_sum = sum;
    for (int i = 0; i < n; i++) {

    }
}

int maximizeMinSum(vector<int>& arr, int k) {
    int low = max_e;
    int high = sum;

    int res = low;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(arr, k, mid)) {
            low = mid + 1;
            res = mid;
        } else {
            high = mid - 1;
        }
    }

    return max_val - res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Find min_val, sum
    int max_e = *max_element(arr.begin(), arr.end());
    for (int i : arr) {
        sum += i;
    }

    cout << minimizeMaxSum(arr, k) << endl;

    return 0;
}
