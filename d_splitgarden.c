#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000000000000LL

long long *a;
long long *dp_max, *dp_min;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    a = (long long*)malloc((n + 1) * sizeof(long long));
    dp_max = (long long*)malloc((n + 1) * sizeof(long long));
    dp_min = (long long*)malloc((n + 1) * sizeof(long long));

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    long long *prev_max = (long long*)malloc((n + 1) * sizeof(long long));
    long long *prev_min = (long long*)malloc((n + 1) * sizeof(long long));

    for (int i = 0; i <= n; i++) {
        prev_max[i] = -INF;
        prev_min[i] = INF;
    }
    prev_max[0] = prev_min[0] = 0;

    for (int k = 1; k <= m; k++) {
        long long best_max = -INF;
        long long best_min = INF;
        for (int i = 1; i <= n; i++) {
            if (prev_max[i - 1] != -INF) {
                if (prev_max[i - 1] + a[i] > best_max) {
                    best_max = prev_max[i - 1] + a[i];
                }
            }
            if (prev_min[i - 1] != INF) {
                if (prev_min[i - 1] + a[i] < best_min) {
                    best_min = prev_min[i - 1] + a[i];
                }
            }

            dp_max[i] = best_max + a[i];
            dp_min[i] = best_min + a[i];
        }

        long long *tmp_max = prev_max;
        long long *tmp_min = prev_min;
        prev_max = dp_max;
        prev_min = dp_min;
        dp_max = tmp_max;
        dp_min = tmp_min;
    }

    printf("%lld\n%lld\n", prev_max[n], prev_min[n]);

    free(a);
    free(dp_max);
    free(dp_min);
    free(prev_max);
    free(prev_min);

    return 0;
}
