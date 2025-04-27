#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *A, const void *B) {
    long long a = *(const long long *)A;
    long long b = *(const long long *)B;
    if (a < b) return -1;
    else if (a > b) return 1;
    else return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *c = (long long *)malloc(n * sizeof(long long));
    long long *b = (long long *)malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
        b[i] = c[i] - (i + 1);
    }

    qsort(b, n, sizeof(long long), cmpfunc);

    long long median = b[n / 2];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long diff = b[i] - median;
        if (diff < 0)
            diff = -diff;
        ans += diff;
    }

    printf("%lld", ans);

    return 0;
}