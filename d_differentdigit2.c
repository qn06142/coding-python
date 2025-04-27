#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

char *n_str;
int n;
int *a;
long long *hash;

inline size_t get_index(int idx, int tight, int p1, int p2, int started) {

    return (((((size_t)idx * 2 + tight) * 11 + p1) * 11 + p2) * 2 + started);
}

long long dp(int idx, int tight, int p1, int p2, int started) {
    if (idx == n) {
        return started ? 1 : 0;
    }
    size_t index = get_index(idx, tight, p1, p2, started);
    if (hash[index] != -1) {
        return hash[index];
    }

    int limit = tight ? a[idx] : 9;
    long long total = 0;

    for (int d = 0; d <= limit; ++d) {
        int ntight = tight && (d == limit);
        int nstarted = started || (d != 0);
        if (!nstarted) {

            total = (total + dp(idx + 1, ntight, 10, 10, 0)) % MOD;
        } else {

            if (d != p1 && d != p2) {
                int np1, np2;
                if (!started) {

                    np1 = d;
                    np2 = 10;
                } else {

                    np1 = d;
                    np2 = p1;
                }
                total = (total + dp(idx + 1, ntight, np1, np2, 1)) % MOD;
            }
        }
    }

    hash[index] = total;
    return total;
}

int main() {

    size_t buf_size = 1000002;
    n_str = malloc(buf_size);
    if (!n_str) return 1;
    if (!fgets(n_str, buf_size, stdin)) return 1;
    n = strlen(n_str);
    if (n_str[n-1] == '\n') {
        n_str[--n] = '\0';
    }

    a = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        a[i] = n_str[i] - '0';
    }

    size_t tot = (size_t)(n + 1) * 2 * 11 * 11 * 2;
    hash = malloc(tot * sizeof(long long));
    for (size_t i = 0; i < tot; ++i) hash[i] = -1;

    long long ans = dp(0, 1, 10, 10, 0);
    printf("%lld\n", ans);
}