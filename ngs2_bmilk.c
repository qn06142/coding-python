#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005

long long a[MAXN];

int main(void) {
    int n, k;
    long long p;
    if (scanf("%d %d %lld", &n, &k, &p) != 3) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    long long piggy_bank = 0;
    int full_groups = n / k;

    for (int i = 0; i < full_groups; ++i) {
        long long sum_group = 0;
        for (int j = i * k; j < (i + 1) * k; ++j) {
            sum_group += a[j];
        }
        if (sum_group >= p) {
            piggy_bank += 20000;
        }
    }

    int rem = n % k;
    if (rem > 0) {
        long long sum_group = 0;
        for (int j = full_groups * k; j < n; ++j) {
            sum_group += a[j];
        }
        if (sum_group >= p) {
            piggy_bank += 20000;
        }
    }

    printf("%lld\n", piggy_bank);
    return 0;
}
