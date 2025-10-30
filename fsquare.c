#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int(const void *pa, const void *pb) {
    int a = *(const int*)pa;
    int b = *(const int*)pb;
    return (a > b) - (a < b);
}

int lower_bound(const int *arr, size_t n, int x) {
    size_t l = 0, r = n;
    while (l < r) {
        size_t mid = (l + r) >> 1;
        if (arr[mid] < x) l = mid + 1;
        else r = mid;
    }
    return (int)l;
}

typedef struct {
    int *a;
    int n, cap;
} ivec;
static void ivec_init(ivec *v) { v->a = NULL; v->n = v->cap = 0; }
static void ivec_push(ivec *v, int x) {
    if (v->n == v->cap) {
        v->cap = v->cap ? v->cap * 2 : 4;
        v->a = realloc(v->a, v->cap * sizeof(int));
    }
    v->a[v->n++] = x;
}

int main(void) {
    #ifdef ONLINE_JUDGE
        freopen("FSQUARE.inp", "r", stdin);
        freopen("FSQUARE.out", "w", stdout);
    #endif

    int m, n, k;
    if (scanf("%d %d %d", &m, &n, &k) != 3) return 0;

    size_t mn = (size_t)m * (size_t)n;
    int *flat = malloc(mn * sizeof(int));
    for (size_t i = 0; i < mn; ++i) scanf("%d", &flat[i]);

    int *tmp = malloc(mn * sizeof(int));
    memcpy(tmp, flat, mn * sizeof(int));
    qsort(tmp, mn, sizeof(int), cmp_int);

    size_t U = 0;
    for (size_t i = 0; i < mn; ++i) if (i == 0 || tmp[i] != tmp[i-1]) tmp[U++] = tmp[i];

    int *compressed = malloc(mn * sizeof(int));
    for (size_t i = 0; i < mn; ++i) compressed[i] = lower_bound(tmp, U, flat[i]);

    int *idmat = malloc(mn * sizeof(int));
    for (int r = 0; r < m; ++r)
        for (int c = 0; c < n; ++c)
            idmat[(size_t)r * n + c] = compressed[(size_t)r * n + c];

    free(flat); free(tmp); free(compressed);

    int **colfreq = malloc((size_t)n * sizeof(int*));
    for (int c = 0; c < n; ++c) colfreq[c] = calloc(U, sizeof(int));

    ivec *cols = malloc((size_t)n * sizeof(ivec));
    for (int c = 0; c < n; ++c) ivec_init(&cols[c]);

    int *freq = calloc(U, sizeof(int));

    int ans = 0;

    for (int r1 = 0; r1 < m; ++r1) {

        for (int c = 0; c < n; ++c) {

            if (cols[c].n) {
                for (int i = 0; i < cols[c].n; ++i) {
                    int id = cols[c].a[i];
                    colfreq[c][id] = 0;
                }
            }
            cols[c].n = 0;
        }

        memset(freq, 0, U * sizeof(int));
        int distinct = 0;
        int l = 0, r = -1; 

        for (int r2 = r1; r2 < m; ++r2) {
            int side = r2 - r1 + 1;
            if (side > n) break; 

            for (int c = 0; c < n; ++c) {
                int id = idmat[(size_t)r2 * n + c];
                if (colfreq[c][id] == 0) ivec_push(&cols[c], id);
                colfreq[c][id]++;

                if (c >= l && c <= r) {
                    if (freq[id] == 0) distinct++;
                    freq[id] += 1;
                }
            }

            while ((r - l + 1) < side && r + 1 < n) {
                r++;

                ivec *v = &cols[r];
                for (int i = 0; i < v->n; ++i) {
                    int id = v->a[i];
                    int add = colfreq[r][id];
                    if (add) {
                        if (freq[id] == 0) distinct++;
                        freq[id] += add;
                    }
                }
            }

            while (distinct > k && l <= r) {
                ivec *v = &cols[l];
                for (int i = 0; i < v->n; ++i) {
                    int id = v->a[i];
                    int sub = colfreq[l][id];
                    if (sub) {
                        freq[id] -= sub;
                        if (freq[id] == 0) distinct--;
                    }
                }
                l++;
            }

            int width = r - l + 1;
            if (width == side && distinct <= k && side > ans) ans = side;
        }
    }

    printf("%d\n", ans);
}