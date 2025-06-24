#include <stdio.h>
#include <inttypes.h>   // for SCNu64
#include <stdint.h>     // for uint64_t

// 64-bit Euclidean gcd
static uint64_t gcd(uint64_t a, uint64_t b) {
    while (b) {
        uint64_t t = b;
        b = a % b;
        a = t;
    }
    return a;
}

#define MAXN 10005

int dp[MAXN];
uint64_t a[MAXN];

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%" SCNu64, &a[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;                       // singleton {a[i]}
        for (int j = 1; j < i; j++) {
            if (gcd(a[i], a[j]) > 1) {
                int cand = dp[j] + 1;
                if (cand > dp[i]) {
                    dp[i] = cand;
                }
            }
        }
        if (dp[i] > ans) {
            ans = dp[i];
        }
    }

    printf("%d\n", ans);
    return 0;
}
