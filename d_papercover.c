#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, m;

    if (scanf("%d %d", &n, &m) != 2) {
        return 1;
    }

    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        board[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    int h, w;
    scanf("%d %d", &h, &w);

    if (h > n || w > m) {
        int possible = 1;
        for (int i = 0; i < n && possible; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1) {
                    possible = 0;
                    break;
                }
            }
        }

        if (possible)
            printf("YES");
        else
            printf("NO");
        return 0;
    }

    int **P = (int **)malloc((n+1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        P[i] = (int *)calloc((m+1), sizeof(int));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            P[i][j] = board[i-1][j-1] + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
        }
    }

    int valid_n = n - h + 1;
    int valid_m = m - w + 1;
    int **valid = (int **)malloc((valid_n+1) * sizeof(int *));
    for (int i = 0; i <= valid_n; i++) {
        valid[i] = (int *)calloc((valid_m+1), sizeof(int));
    }

    for (int a = 1; a <= valid_n; a++) {
        for (int b = 1; b <= valid_m; b++) {
            int i2 = a + h - 1;
            int j2 = b + w - 1;
            int sum = P[i2][j2] - P[a-1][j2] - P[i2][b-1] + P[a-1][b-1];
            if (sum == h * w) {
                valid[a][b] = 1;
            }
        }
    }

    int **Q = (int **)malloc((valid_n+1) * sizeof(int *));
    for (int i = 0; i <= valid_n; i++) {
        Q[i] = (int *)calloc((valid_m+1), sizeof(int));
    }

    for (int i = 1; i <= valid_n; i++) {
        for (int j = 1; j <= valid_m; j++) {
            Q[i][j] = valid[i][j] + Q[i-1][j] + Q[i][j-1] - Q[i-1][j-1];
        }
    }

    int possible = 1;

    for (int i = 1; i <= n && possible; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i-1][j-1] == 1) {

                int a_low = max(1, i - h + 1);
                int a_high = min(i, valid_n);
                int b_low = max(1, j - w + 1);
                int b_high = min(j, valid_m);
                if (a_low > a_high || b_low > b_high) {
                    possible = 0;
                    break;
                }
                int sumvalid = Q[a_high][b_high] - Q[a_low - 1][b_high] - Q[a_high][b_low - 1] + Q[a_low - 1][b_low - 1];
                if (sumvalid == 0) {
                    possible = 0;
                    break;
                }
            }
        }
    }

    if (possible)
        printf("YES");
    else
        printf("NO");

    return 0;
}