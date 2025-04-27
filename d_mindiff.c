#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return ia - ib;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), cmp);

    long long *dp = (long long *)malloc(n * n * sizeof(long long));
    const long long INF = 1LL << 60;
    for (int i = 0; i < n * n; i++)
    {
        dp[i] = INF;
    }

    for (int i = 0; i < n; i++)
    {
        dp[i * n + i] = 0;
    }

    for (int len = 1; len <= n; len++)
    {
        for (int l = 0; l <= n - len; l++)
        {
            int r = l + len - 1;
            long long cost = dp[l * n + r];
            if (cost == INF)
                continue;

            if (l > 0)
            {
                long long new_cost = cost + (long long)arr[r] - arr[l - 1];
                if (new_cost < dp[(l - 1) * n + r])
                    dp[(l - 1) * n + r] = new_cost;
            }

            if (r < n - 1)
            {
                long long new_cost = cost + (long long)arr[r + 1] - arr[l];
                if (new_cost < dp[l * n + (r + 1)])
                    dp[l * n + (r + 1)] = new_cost;
            }
        }
    }

    printf("%lld\n", dp[0 * n + (n - 1)]);

    free(arr);
    free(dp);
    return 0;
}