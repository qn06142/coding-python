#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define MOD 1000000007

int64_t mod_add(int64_t a, int64_t b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    char s[1005];
    int x, k;

    if (scanf("%s %d %d", s, &x, &k) != 3) return 0;
    int len = strlen(s);

    int states = (k + 1) * 2 * 2;
    int64_t *dp_cur  = malloc(states * sizeof(int64_t));
    int64_t *dp_next = malloc(states * sizeof(int64_t));
    if (!dp_cur || !dp_next) return 0;

    for (int i = 0; i < states; i++) dp_cur[i] = 0;

    #define IDX(c, t, z) ((((c) * 2 + (t)) * 2) + (z))

    dp_cur[IDX(0,1,1)] = 1;

    for (int pos = 0; pos < len; pos++) {

        for (int i = 0; i < states; i++) dp_next[i] = 0;

        int limit = s[pos] - '0';

        for (int c = 0; c <= k; c++) {
            for (int tight = 0; tight <= 1; tight++) {
                for (int z = 0; z <= 1; z++) {
                    int64_t ways = dp_cur[IDX(c,tight,z)];
                    if (!ways) continue;
                    int maxd = tight ? limit : 9;
                    for (int d = 0; d <= maxd; d++) {
                        int tight2 = (tight && (d == maxd));
                        int z2     = (z && (d == 0));
                        int c2 = c;

                        if (!z2 && d == x) c2++;
                        if (c2 > k) continue;
                        int idx = IDX(c2, tight2, z2);
                        dp_next[idx] = mod_add(dp_next[idx], ways);
                    }
                }
            }
        }

        int64_t *tmp = dp_cur;
        dp_cur  = dp_next;
        dp_next = tmp;
    }

    int64_t result = 0;
    result = mod_add(result, dp_cur[IDX(k,0,0)]);
    result = mod_add(result, dp_cur[IDX(k,1,0)]);
    printf("%lld\n", (long long)result);

    free(dp_cur);
    free(dp_next);
    return 0;
}