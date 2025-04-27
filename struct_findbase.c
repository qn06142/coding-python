#include<stdio.h>
#include<math.h>
long long binpow(long long base, int exp) {
    long long res = 1;
    while (exp) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}
#define min(a,b) \
({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
  _a < _b ? _a : _b; })
int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        long long x;
        scanf("%lld", &x);
        if(x == 1) {
            printf("1\n");
            continue;
        }
        long long ans = x;
        for (int b = 2; b < 64; ++b) { 
            long long l = 1, r = pow(x, 1.0 / b) + 1;
            while (l <= r) {
                long long mid = l + (r - l) / 2;
                long long mid_pow = binpow(mid, b);
                if (mid_pow == x) {
                    ans = min(ans, mid);
                    break;
                } else if (mid_pow < x) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        printf("%lld\n", ans);
    }
}