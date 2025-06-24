#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static const int MAXN = 100000;
static const int MAXQ = 100000;
static int n, q;
static int a[MAXN+1], comp[MAXN+1], coord[MAXN];
static long long res[MAXQ];

struct query {
    int l, r, idx, block;
} Q[MAXQ];

static int cnt[MAXN+2];
static long long sumpos[MAXN+2];

static int cmp_int(const void *p, const void *q) {
    int x = *(const int*)p;
    int y = *(const int*)q;
    return (x < y ? -1 : x > y);
}

static int cmpQ(const void *p, const void *q) {
    const struct query *A = (const query*) p;
    const struct query *B = (const query*) q;
    if (A->block != B->block) return A->block - B->block;
    if (A->block & 1) return B->r - A->r;
    return A->r - B->r;
}

int main() {
    if (scanf("%d %d", &n, &q) != 2) return 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        coord[i-1] = a[i];
    }
    qsort(coord, n, sizeof coord[0], cmp_int);
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || coord[i] != coord[i-1]) coord[m++] = coord[i];
    }
    for (int i = 1; i <= n; i++) {
        int lo = 0, hi = m;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (coord[mid] < a[i]) lo = mid + 1;
            else hi = mid;
        }
        comp[i] = lo;  // 0..m-1
    }
    int blk = (int)(sqrt(n));
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].idx = i;
        Q[i].block = Q[i].l / blk;
    }
    qsort(Q, q, sizeof Q[0], cmpQ);

    int l = 1, r = 0;
    long long ans = 0;

    for (int i = 0; i < q; i++) {
        int L = Q[i].l;
        int R = Q[i].r;
        // expand R
        while (r < R) {
            r++;
            int v = comp[r];
            ans += (long long)cnt[v] * r - sumpos[v];
            cnt[v]++;
            sumpos[v] += r;
        }
        // shrink R
        while (r > R) {
            int v = comp[r];
            cnt[v]--;
            sumpos[v] -= r;
            ans -= (long long)cnt[v] * r - sumpos[v];
            r--;
        }
        // expand L
        while (l > L) {
            l--;
            int v = comp[l];
            ans += sumpos[v] - (long long)cnt[v] * l;
            cnt[v]++;
            sumpos[v] += l;
        }
        // shrink L
        while (l < L) {
            int v = comp[l];
            cnt[v]--;
            sumpos[v] -= l;
            ans -= sumpos[v] - (long long)cnt[v] * l;
            l++;
        }
        res[Q[i].idx] = ans;
    }

    for (int i = 0; i < q; i++) {
        printf("%lld\n", res[i]);
    }
}
