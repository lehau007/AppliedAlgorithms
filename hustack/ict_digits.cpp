#include <stdio.h>
#include <stdbool.h>

// Anh thuong em, em thuong ai

int digit_size = 7, ict_value = 0, k62_value = 62, hust_value = 0;
bool visited[10];
int ans = 0, n;

// i, c, t, h, u, s, k

void backtrack(int idx) {
    if (idx == digit_size) {
        if (ict_value - k62_value + hust_value == n)
            ans += 1;
        return;
    }

    for (int i = 1; i < 10; i++) {
        if (visited[i])
            continue;

        visited[i] = true;
        if (idx == 0) {
            ict_value += 100 * i;
            backtrack(idx + 1);
            ict_value -= 100 * i;
        } else if (idx == 1) {
            ict_value += 10 * i;
            backtrack(idx + 1);
            ict_value -= 10 * i;
        } else if (idx == 2) {
            ict_value += i;
            hust_value += i;
            backtrack(idx + 1);
            ict_value -= i;
            hust_value -= i;
        } else if (idx == 3) {
            hust_value += 1000 * i;
            backtrack(idx + 1);
            hust_value -= 1000 * i;
        } if (idx == 4) {
            hust_value += 100 * i;
            backtrack(idx + 1);
            hust_value -= 100 * i;
        } else if (idx == 5) {
            hust_value += 10 * i;
            backtrack(idx + 1);
            hust_value -= 10 * i;
        } else if (idx == 6) {
            k62_value += 100 * i;
            backtrack(idx + 1);
            k62_value -= 100 * i;
        }

        visited[i] = false;
    }
}

int main() {
    for (int i = 0; i < 10; i++)
        visited[i] = false;

    scanf("%d", &n);
    backtrack(0);

    printf("%d", ans);
    return 0;
}

