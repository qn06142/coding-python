#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#define MAXL 20

#define IDX(l,x,y)  (((l) * 10 + (x)) * 10 + (y))

int main() {
    uint64_t k;
    if (scanf("%" SCNu64, &k) != 1) return 0;

    if (k <= 9) {

        printf("%" PRIu64, k);
        return 0;
    }

    if (k <= 90) {

        printf("%" PRIu64, 9 + k);
        return 0;
    }
    k -= 90;

    uint64_t *dp = calloc((MAXL + 1) * 10 * 10, sizeof(uint64_t));

    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            if (x != y) dp[IDX(2,x,y)] = 1;
        }
    }

    uint64_t count_len[MAXL+1] = {0};

    for (int L = 3; L <= MAXL; ++L) {
        for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                uint64_t sum = 0;
                if (x != y) {
                    for (int w = 0; w < 10; ++w) {
                        if (w != x && w != y) {
                            sum += dp[IDX(L-1, w, x)];
                        }
                    }
                }
                dp[IDX(L, x, y)] = sum;
            }
        }

        uint64_t total = 0;
        for (int d1 = 1; d1 <= 9; ++d1)
            for (int d2 = 0; d2 <= 9; ++d2)
                if (d1 != d2)
                    total += dp[IDX(L, d1, d2)];
        count_len[L] = total;
    }

    uint64_t prefix_sum = 0;
    int Lstar = 3;
    for (; Lstar <= MAXL; ++Lstar) {
        if (prefix_sum + count_len[Lstar] >= k) break;
        prefix_sum += count_len[Lstar];
    }
    uint64_t offset = k - prefix_sum;  

    int digits[MAXL];

    for (int d1 = 1; d1 <= 9; ++d1) {
        uint64_t block = 0;
        for (int d2 = 0; d2 <= 9; ++d2)
            if (d2 != d1)
                block += dp[IDX(Lstar, d1, d2)];
        if (offset > block) {
            offset -= block;
        } else {
            digits[0] = d1;
            break;
        }
    }

    for (int d2 = 0; d2 <= 9; ++d2) {
        if (d2 == digits[0]) continue;
        uint64_t block = dp[IDX(Lstar, digits[0], d2)];
        if (offset > block) {
            offset -= block;
        } else {
            digits[1] = d2;
            break;
        }
    }

    for (int i = 2; i < Lstar; ++i) {
        int p1 = digits[i-2];
        int p2 = digits[i-1];
        for (int d = 0; d < 10; ++d) {
            if (d == p1 || d == p2) continue;

            int rem = (Lstar - (i + 1)) + 2;
            uint64_t block = dp[IDX(rem, p2, d)];
            if (offset > block) {
                offset -= block;
            } else {
                digits[i] = d;
                break;
            }
        }
    }

    for (int i = 0; i < Lstar; ++i) {
        putchar('0' + digits[i]);
    }
    putchar('\n');
    return 0;
}