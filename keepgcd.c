#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long phi(long long n) {
    long long result = n;
    for (long long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long x, z;
        scanf("%lld %lld", &x, &z);
        long long d = gcd(x, z);
        long long b = z / d;

        long long ans = phi(b);
        printf("%lld\n", ans);
    }
    return 0;
}