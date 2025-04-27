#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int h, i;
} pair;

int cmp(const void *p1, const void *p2) {
    pair *a = (pair*) p1;
    pair *b = (pair*) p2;

    return b->h - a->h;
}

int find(int *par, int i) {
    if (par[i] != i)
        par[i] = find(par, par[i]);
    return par[i];
}

int union_op(int *par, int *rnk, int i, int j) {
    int ri = find(par, i);
    int rj = find(par, j);
    if (ri == rj)
        return 0;
    if (rnk[ri] < rnk[rj])
        par[ri] = rj;
    else if (rnk[ri] > rnk[rj])
        par[rj] = ri;
    else {
        par[rj] = ri;
        rnk[ri]++;
    }
    return 1;
}

int main() {
    int n;
    if(scanf("%d", &n) != 1)
        return 1;

    int *a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    pair *p = (pair*) malloc(n * sizeof(pair));
    for (int i = 0; i < n; i++) {
        p[i].h = a[i];
        p[i].i = i;
    }

    qsort(p, n, sizeof(pair), cmp);

    int *added = (int*) calloc(n, sizeof(int)); 
    int *par = (int*) malloc(n * sizeof(int));
    int *rnk = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }

    int isl = 0, max_isl = 0;
    int idx = 0;
    while (idx < n) {
        int cur_h = p[idx].h;

        int start = idx;
        while (idx < n && p[idx].h == cur_h)
            idx++;

        for (int j = start; j < idx; j++) {
            int pos = p[j].i;
            added[pos] = 1;
            isl++;
        }

        for (int j = start; j < idx; j++) {
            int pos = p[j].i;
            for (int d = -1; d <= 1; d += 2) { 
                int nb = pos + d;
                if (nb >= 0 && nb < n && added[nb]) {
                    if (union_op(par, rnk, pos, nb))
                        isl--;
                }
            }
        }
        if (isl > max_isl)
            max_isl = isl;
    }

    printf("%d\n", max_isl);
    return 0;
}