#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef long long ll;

typedef struct {
    ll x;
} RA;

typedef struct {
    ll y;
} RB;

typedef struct {
    ll w, s;
} Obj;

int cmp_ra(const void *a, const void *b) {
    RA *p = (RA*)a;
    RA *q = (RA*)b;
    return (p->x > q->x) - (p->x < q->x);
}

int cmp_rb(const void *a, const void *b) {
    RB *p = (RB*)a;
    RB *q = (RB*)b;
    return (p->y > q->y) - (p->y < q->y);
}

int cmp_w(const void *a, const void *b) {
    Obj *p = (Obj*)a;
    Obj *q = (Obj*)b;
    return (p->w > q->w) - (p->w < q->w);
}

int cmp_s(const void *a, const void *b) {
    Obj *p = (Obj*)a;
    Obj *q = (Obj*)b;
    return (p->s > q->s) - (p->s < q->s);
}

int n, m, t;
RA *ra = NULL;
RB *rb = NULL;
Obj *ga = NULL, *gb = NULL, *gbt = NULL;
Obj *gbt_w = NULL, *gbt_s = NULL;
int ca = 0, cb = 0, cbt = 0;

bool ok(ll min_t) {
    ll *cap_a = malloc(n * sizeof(ll));
    ll *cap_b = malloc(m * sizeof(ll));
    for (int i = 0; i < n; i++) cap_a[i] = min_t;
    for (int i = 0; i < m; i++) cap_b[i] = min_t;

    int i = 0;
    for (int j = 0; j < ca; j++) {
        while (i < n && (cap_a[i] == 0 || ra[i].x <= ga[j].w)) i++;
        if (i == n) { free(cap_a); free(cap_b); return false; }
        cap_a[i]--;
    }

    i = 0;
    for (int j = 0; j < cb; j++) {
        while (i < m && (cap_b[i] == 0 || rb[i].y <= gb[j].s)) i++;
        if (i == m) { free(cap_a); free(cap_b); return false; }
        cap_b[i]--;
    }

    bool res = false;
    for (int ord = 0; ord < 2 && !res; ord++) {
        ll *tmp_a = malloc(n * sizeof(ll));
        ll *tmp_b = malloc(m * sizeof(ll));
        for (i = 0; i < n; i++) tmp_a[i] = cap_a[i];
        for (i = 0; i < m; i++) tmp_b[i] = cap_b[i];

        int cnt = 0;
        int *unass = malloc(cbt * sizeof(int));
        int un_cnt = 0;

        if (ord == 0) {
            i = 0;
            for (int j = 0; j < cbt; j++) {
                while (i < n && (tmp_a[i] == 0 || ra[i].x <= gbt_w[j].w)) i++;
                if (i < n) { tmp_a[i]--; cnt++; }
                else unass[un_cnt++] = j;
            }

            i = 0;
            for (int j = 0; j < un_cnt; j++) {
                while (i < m && (tmp_b[i] == 0 || rb[i].y <= gbt_s[unass[j]].s)) i++;
                if (i < m) { tmp_b[i]--; cnt++; }
            }
        } else {
            i = 0;
            for (int j = 0; j < cbt; j++) {
                while (i < m && (tmp_b[i] == 0 || rb[i].y <= gbt_s[j].s)) i++;
                if (i < m) { tmp_b[i]--; cnt++; }
            }

            i = 0;
            for (int j = 0; j < cbt; j++) {
                while (i < n && (tmp_a[i] == 0 || ra[i].x <= gbt_w[j].w)) i++;
                if (i < n) { tmp_a[i]--; cnt++; }
            }
        }

        if (cnt >= cbt) res = true;
        free(tmp_a); free(tmp_b); free(unass);
    }

    free(cap_a); free(cap_b);
    return res;
}

int main(void) {
    scanf("%d %d %d", &n, &m, &t);

    if (n > 0) {
        ra = malloc(n * sizeof(RA));
        for (int i = 0; i < n; i++) scanf("%lld", &ra[i].x);
        qsort(ra, n, sizeof(RA), cmp_ra);
    }

    if (m > 0) {
        rb = malloc(m * sizeof(RB));
        for (int i = 0; i < m; i++) scanf("%lld", &rb[i].y);
        qsort(rb, m, sizeof(RB), cmp_rb);
    }

    ll max_a = (n > 0) ? ra[n-1].x : 0;
    ll max_b = (m > 0) ? rb[m-1].y : 0;

    ga = malloc(t * sizeof(Obj));
    gb = malloc(t * sizeof(Obj));
    gbt = malloc(t * sizeof(Obj));

    for (int i = 0; i < t; i++) {
        Obj o; scanf("%lld %lld", &o.w, &o.s);

        if (o.w < max_a && o.s < max_b) gbt[cbt++] = o;
        else if (o.w < max_a) ga[ca++] = o;
        else if (o.s < max_b) gb[cb++] = o;
        else { printf("-1\n"); return 0; }
    }

    qsort(ga, ca, sizeof(Obj), cmp_w);
    qsort(gb, cb, sizeof(Obj), cmp_s);

    gbt_w = malloc(cbt * sizeof(Obj));
    gbt_s = malloc(cbt * sizeof(Obj));
    for (int i = 0; i < cbt; i++) { gbt_w[i] = gbt[i]; gbt_s[i] = gbt[i]; }
    qsort(gbt_w, cbt, sizeof(Obj), cmp_w);
    qsort(gbt_s, cbt, sizeof(Obj), cmp_s);

    ll lo = (t + n + m - 1) / (n + m), hi = t, ans = -1;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (ok(mid)) { ans = mid; hi = mid - 1; }
        else lo = mid + 1;
    }

    printf("%lld\n", ans);
}
