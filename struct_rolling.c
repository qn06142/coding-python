#include <stdio.h>

int main(void) {
    long long m, n;
    scanf("%lld %lld", &m, &n);

    long long Q = (n - 1) / 4;
    long long R = (n - 1) % 4;

    int L = 0;

    long long cycle[10];  

    if (R == 0) {

        L = 4;
        cycle[0] = 6 + 14 * Q;
        cycle[1] = 5 + 14 * Q;
        cycle[2] = 1 + 14 * Q;
        cycle[3] = 2 + 14 * Q;
    }
    else if (R == 1) {

        L = 6;
        cycle[0] = 10 + 14 * Q;
        cycle[1] = 11 + 14 * Q;
        cycle[2] = 8 + 14 * Q;
        cycle[3] = 4 + 14 * Q;
        cycle[4] = 3 + 14 * Q;
        cycle[5] = 6 + 14 * Q;
    }
    else if (R == 2) {

        L = 2;
        cycle[0] = 11 + 14 * Q;
        cycle[1] = 11 + 14 * Q;
    }
    else { 

        L = 4;
        cycle[0] = 14 + 14 * Q;
        cycle[1] = 14 + 14 * Q;
        cycle[2] = 14 + 14 * Q;
        cycle[3] = 14 + 14 * Q;
    }

    long long ans = 0;
    for (int i = 0; i < L; i++) {
        ans += cycle[i];
    }

    long long full = m / L;
    long long rem = m % L;

    long long total = full * ans;
    for (int i = 0; i < rem; i++) {
        total += cycle[i];
    }

    printf("%lld\n", total);
    return 0;
}