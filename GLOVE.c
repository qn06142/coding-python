#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#pragma GCC optimize("trapv")
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long solve(int a[], int n, int b[], int m) {

    if (m < n) {
        return -1;
    }

    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);

    long long dp[n+1][m+1];

    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = LLONG_MAX;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= m; j++) {

            if (dp[i][j-1] < dp[i][j]) {
                dp[i][j] = dp[i][j-1];
            }

            if (dp[i-1][j-1] != LLONG_MAX) {
                long long cost = abs(a[i-1] - b[j-1]);
                if (dp[i-1][j-1] + cost < dp[i][j]) {
                    dp[i][j] = dp[i-1][j-1] + cost;
                }
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    int b[m];
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i - 1]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &b[i - 1]);
    }

    if (m < n) {
        return 1;
    }

    long long result = solve(a, n, b, m);
    if(result != -1)
        printf("%lld", result);

    return 0;
}