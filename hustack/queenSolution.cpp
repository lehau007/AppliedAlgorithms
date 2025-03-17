#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n; 
int **board;

bool *markR, *markC, *markleft, *markright;

void init() {
    markR = (bool*)malloc(n * sizeof(bool));
    markC = (bool*)malloc(n * sizeof(bool));
    markleft = (bool*)malloc(2 * n * sizeof(bool));
    markright = (bool*)malloc(2 * n * sizeof(bool));
    
    for (int i = 0; i < n; i++) {
        markR[i] = false;
        markC[i] = false;
    }
    for (int i = 0; i < 2 * n; i++) {
        markleft[i] = false;
        markright[i] = false;
    }
}

void set(int r, int c) {
    markR[r] = true;
    markC[c] = true;
    markleft[r - c + n] = true;
    markright[r + c] = true;
}

void reset(int r, int c) {
    markR[r] = false;
    markC[c] = false;
    markleft[r - c + n] = false;
    markright[r + c] = false;
}

bool isvalid(int r, int c) {
    return !(markR[r] || markC[c] || markleft[r - c + n] || markright[r + c]);
}

int backtracking(int r, int c, int cnt) {
    if (cnt == n) {
        return 1;
    }

    if (r == n) {
        return 0;
    }

    if (c == n) {
        return backtracking(r + 1, 0, cnt);
    }

    if (board[r][c] == 1) {
        return backtracking(r, c + 1, cnt);
    }
    
    int ans = 0;
    if (isvalid(r, c)) {
        board[r][c] = 1;
        set(r, c);
        ans += backtracking(r, c + 1, cnt + 1);
        reset(r, c);
        board[r][c] = 0;
    } 

    ans += backtracking(r, c + 1, cnt);
    return ans;
}

int main() {
    scanf("%d", &n);
    
    init();
    board = (int**)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        board[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    int cnt = 0;
    int k; 
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int r, c; 
        scanf("%d%d", &r, &c);
        r -= 1; 
        c -= 1;

        if (!isvalid(r, c)) {
            printf("0");
            return 0;
        } 
        board[r][c] = 1;

        // mark something
        set(r, c);
        cnt += 1;
    }

    printf("%d\n", backtracking(0, 0, cnt));

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);
    free(markR);
    free(markC);
    free(markleft);
    free(markright);

    return 0;
}
