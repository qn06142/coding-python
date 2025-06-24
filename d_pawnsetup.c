#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD 1000000007

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int max_mask = 1 << m;

    int *dp_prev = (int*)malloc(max_mask * sizeof(int));
    int *dp_curr = (int*)malloc(max_mask * sizeof(int));

    memset(dp_prev, 0, max_mask * sizeof(int));
    dp_prev[0] = 1;

    char **ok = (char**)malloc(max_mask * sizeof(char*));
    for (int i = 0; i < max_mask; i++) {
        ok[i] = (char*)malloc(max_mask * sizeof(char));
        for (int j = 0; j < max_mask; j++) {

            if (((i << 1) & j) == 0 && ((i >> 1) & j) == 0)
                ok[i][j] = 1;
            else
                ok[i][j] = 0;
        }
    }

    for (int row = 1; row <= n; row++) {

        memset(dp_curr, 0, max_mask * sizeof(int));

        for (int mask2 = 0; mask2 < max_mask; mask2++) {
            long long sum = 0;
            for (int mask1 = 0; mask1 < max_mask; mask1++) {
                if (ok[mask1][mask2]) {
                    sum += dp_prev[mask1];
                    if (sum >= MOD) sum -= MOD;
                }
            }
            dp_curr[mask2] = (int)sum;
        }

        int *tmp = dp_prev;
        dp_prev = dp_curr;
        dp_curr = tmp;
    }

    long long result = 0;
    for (int mask = 0; mask < max_mask; mask++) {
        result = (result + dp_prev[mask]) % MOD;
    }

    printf("%lld\n", result);
}