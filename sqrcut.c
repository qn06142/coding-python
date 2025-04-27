#include <stdio.h>

int main() {

    unsigned long long m, n;

    scanf("%llu %llu", &m, &n);

    unsigned long long count = 0;

    while (m != 0 && n != 0) {
        if (m >= n) {
            count += m / n; 
            m %= n;         
        } else {
            count += n / m; 
            n %= m;         
        }
    }

    printf("%llu\n", count);

    return 0;
}