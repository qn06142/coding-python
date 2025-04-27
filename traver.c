#include <stdio.h>
#include <stdlib.h>

#define MOD 9901

typedef struct {
    int n;
    int *f;  
} fenwick_t;

fenwick_t *fenwick_create(int n) {
    fenwick_t *fw = malloc(sizeof(fenwick_t));
    fw->n = n;
    fw->f = calloc(n+1, sizeof(int));
    return fw;
}

void fenwick_update(fenwick_t *fw, int i, int v) {
    while (i <= fw->n) {
        fw->f[i] = (fw->f[i] + v) % MOD;
        i += i & -i;
    }
}

int fenwick_query(fenwick_t *fw, int i) {
    int s = 0;
    while (i > 0) {
        s = (s + fw->f[i]) % MOD;
        i -= i & -i;
    }
    return s;
}

int lower_bound(int *arr, int n, int x) {
    int l = 0, r = n;  
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}

int cmp_int(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    return (x < y ? -1 : x > y);
}

int main() {
    int N;
    long long H;
    scanf("%d %lld", &N, &H);

    int *a = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    int *vals = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        vals[i] = a[i];
    qsort(vals, N, sizeof(int), cmp_int);
    int M = 1;
    for (int i = 1; i < N; i++)
        if (vals[i] != vals[i-1])
            vals[M++] = vals[i];

    fenwick_t *fw = fenwick_create(M);
    int *dp = malloc(N * sizeof(int));
    int answer = 0;

    for (int i = 0; i < N; i++) {

        int lo = lower_bound(vals, M, (int)(a[i] - H));
        int hi = lower_bound(vals, M, (int)(a[i] + H + 1)) - 1;
        int sum_range = 0;
        if (lo <= hi) {

            sum_range = (fenwick_query(fw, hi+1) - fenwick_query(fw, lo) + MOD) % MOD;
        }

        dp[i] = (1 + sum_range) % MOD;

        answer = (answer + dp[i] - 1 + MOD) % MOD;

        int pos = lower_bound(vals, M, a[i]);  
        fenwick_update(fw, pos+1, dp[i]);
    }

    printf("%d\n", answer);
    return 0;
}