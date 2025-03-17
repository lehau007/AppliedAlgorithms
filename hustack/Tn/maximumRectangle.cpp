#include <vector>
#include <stack>
#include <iostream>

class Stack {
public:
    std::vector<std::vector<int>> stack;
    int size;

    Stack() {
        size = 0;
    }

    void push(int val, int cur_count = 1, int pre_count = 0) {
        stack.push_back({val, cur_count, pre_count});
        size++;
    }

    void change_count(int plus) {
        if (!isEmpty()) {
            stack.back()[1] += plus;
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        } else {
            stack.pop_back();
            size--;
            return 1;
        }
    }

    std::vector<int> peek() const {
        if (size != 0) {
            return stack.back();
        } else {
            return {-1, -1, -1};
        }
    }

    void printf() const {
        for (const auto& item : stack) {
            std::cout << item[0] << " " << item[1] << " " << item[2] << std::endl;
        }
    }
};

class HistoryGram {
public:
    int largestRectangleArea(const std::vector<int>& heights) {
        int ans = 0;
        std::stack<int> stack;

        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[i] < heights[stack.top()]) {
                int h = heights[stack.top()];
                stack.pop();
                int w = i - (stack.empty() ? 0 : stack.top() + 1);
                ans = std::max(ans, h * w);
            }
            stack.push(i);
        }

        while (!stack.empty()) {
            int h = heights[stack.top()];
            stack.pop();
            int w = heights.size() - (stack.empty() ? 0 : stack.top() + 1);
            ans = std::max(ans, h * w);
        }

        return ans;
    }
};

class Solution {
public:
    int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<int> heights(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            bool reset = false;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    reset = true;
                    break;
                }
            }
            if (reset) {
                ans = std::max(ans, HistoryGram().largestRectangleArea(heights));
            }

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
        }

        ans = std::max(ans, HistoryGram().largestRectangleArea(heights));
        return ans;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    
    int m; int n; std::cin >> m >> n;
    std::vector<std::vector<char>> maze(m, std::vector<char>(n));
    
    int val;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> val;
            maze[i][j] = val + '0';
        }
    }

    std::cout << Solution().maximalRectangle(maze);
    return 0;
}