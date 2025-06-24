#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#define INF ((long long)9e18)

int main() {
    int n, k, x;
    if (scanf("%d %d %d", &n, &k, &x) != 3) return 0;
    long long *prices = malloc((size_t)n * sizeof(long long));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &prices[i]);
    }

    int mask_width = k - 1;
    size_t full_size = 1u << mask_width;
    size_t dp_bytes = full_size * sizeof(long long);

    long long *dp_cur = mmap(NULL, dp_bytes,
                             PROT_READ | PROT_WRITE,
                             MAP_PRIVATE | MAP_ANONYMOUS,
                             -1, 0);
    long long *dp_next = mmap(NULL, dp_bytes,
                              PROT_READ | PROT_WRITE,
                              MAP_PRIVATE | MAP_ANONYMOUS,
                              -1, 0);
    if (dp_cur == MAP_FAILED || dp_next == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    char *seen_next = calloc(full_size, 1);
    if (!seen_next) return 1;

    int *active_cur  = malloc(full_size * sizeof(int));
    int *active_next = malloc(full_size * sizeof(int));
    int cur_cnt = 1, next_cnt;
    active_cur[0] = 0;

    dp_cur[0] = 0;

    for (int i = 0; i < n; i++) {
        next_cnt = 0;
        long long price = prices[i];
        for (int idx = 0; idx < cur_cnt; idx++) {
            int mask = active_cur[idx];
            long long cost = dp_cur[mask];

            int pc = __builtin_popcount(mask);
            for (int b = 0; b < 2; b++) {
                int total = pc + b;
                if (i + 1 >= k) {
                    if (total != x) continue;
                } else {
                    if (total > x) continue;
                }
                int new_mask = ((mask << 1) | b) & (int)(full_size - 1);
                long long new_cost = cost + (b ? 0 : price);

                if (!seen_next[new_mask]) {
                    seen_next[new_mask] = 1;
                    dp_next[new_mask] = new_cost;
                    active_next[next_cnt++] = new_mask;
                } else if (new_cost < dp_next[new_mask]) {
                    dp_next[new_mask] = new_cost;
                }
            }
        }
        for (int i2 = 0; i2 < next_cnt; i2++) {
            seen_next[ active_next[i2] ] = 0;
        }
        for (int i2 = 0; i2 < cur_cnt; i2++) {
            dp_cur[ active_cur[i2] ] = 0;
        }
        long long *tmp_dp = dp_cur; dp_cur = dp_next; dp_next = tmp_dp;
        int *tmp_act = active_cur; active_cur = active_next; active_next = tmp_act;
        cur_cnt = next_cnt;
    }
    long long ans = INF;
    for (int i = 0; i < cur_cnt; i++) {
        long long c = dp_cur[ active_cur[i] ];
        if (c < ans) ans = c;
    }
    printf("%lld\n", ans);

    return 0;
}
