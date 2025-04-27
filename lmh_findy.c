#include <stdio.h>
#include <math.h>

long long solve(int x) {
    long long max_val = 0;
    for (int d = 1; d <= sqrt(x); ++d) {
        if (x % d == 0) {
            int d1 = d;
            int d2 = x / d;

            long long k1 = (x - 1) / d1;
            long long val1 = 1LL * d1 * d1 * k1;
            if (val1 > max_val) max_val = val1;

            if (d1 != d2) {
                long long k2 = (x - 1) / d2;
                long long val2 = 1LL * d2 * d2 * k2;
                if (val2 > max_val) max_val = val2;
            }
        }
    }
    return max_val;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", solve(x));
    }
    return 0;
}
