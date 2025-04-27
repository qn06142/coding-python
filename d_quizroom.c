#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 1005
#define MAX_M 1005
#define MAX_SIZE (MAX_N * MAX_M)

typedef struct {
    int i, j, v;
} Cell;

int comp(const void* a, const void* b) {
    Cell x = *(const Cell*)a;
    Cell y = *(const Cell*)b;
    if(x.v < y.v) return -1;
    if(x.v > y.v) return 1;
    return 0;
}

int dp[MAX_N][MAX_M]; 
Cell a[MAX_SIZE];
int n, m;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int g[MAX_N][MAX_M];  
int main() {
    scanf("%d %d", &n, &m);
    int iter = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            scanf("%d", &x);
            g[i][j] = x;
            a[iter].i = i;
            a[iter].j = j;
            a[iter].v = x;
            iter++;
        }
    }

    qsort(a + 1, n * m, sizeof(Cell), comp);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    int ans = 0;

    for (int k = 1; k <= n * m; k++) {
        int i = a[k].i, j = a[k].j;

        if (i > 1 && g[i-1][j] < g[i][j])
            dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
        if (i < n && g[i+1][j] < g[i][j])
            dp[i][j] = max(dp[i][j], dp[i+1][j] + 1);
        if (j > 1 && g[i][j-1] < g[i][j])
            dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
        if (j < m && g[i][j+1] < g[i][j])
            dp[i][j] = max(dp[i][j], dp[i][j+1] + 1);

        ans = max(ans, dp[i][j]);
    }
    printf("%d\n", ans + 1);
    return 0;
}