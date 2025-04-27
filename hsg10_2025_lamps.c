#include <stdio.h>
#include <math.h>

int main() {
    int T;

    scanf("%d", &T);

    while(T--) {
        long long n, m;

        scanf("%lld %lld", &n, &m);

        long long A = (long long)floor(sqrt((double)n));
        long long B = (long long)floor(sqrt((double)m));

        long long result = A * m + B * n - 2 * A * B;

        printf("%lld\n", result);
    }

    return 0;
}