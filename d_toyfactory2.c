#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int n, m;
int *a;
int **seg;      
int *sz;        

int* merge_arr(int *a, int asz, int *b, int bsz, int *out_sz) {
    int *c = malloc((asz + bsz) * sizeof(int));
    int i=0, j=0, k=0;
    while (i<asz && j<bsz) {
        if (a[i] < b[j]) c[k++] = a[i++];
        else            c[k++] = b[j++];
    }
    while (i<asz) c[k++] = a[i++];
    while (j<bsz) c[k++] = b[j++];
    *out_sz = k;
    return c;
}

void build(int node, int l, int r) {
    if (l == r) {
        sz[node] = 1;
        seg[node] = malloc(sizeof(int));
        seg[node][0] = a[l];
    } else {
        int mid = (l + r) >> 1;
        build(node<<1, l, mid);
        build(node<<1|1, mid+1, r);
        seg[node] = merge_arr(seg[node<<1], sz[node<<1],
                              seg[node<<1|1], sz[node<<1|1],
                              &sz[node]);
    }
}

int count_in_node(int node, int x, int y) {

    int *v = seg[node], m = sz[node];
    int lo = 0, hi = m;
    while (lo < hi) {
        int md = (lo+hi)>>1;
        if (v[md] < x) lo = md+1; else hi = md;
    }
    int L = lo;

    lo = 0; hi = m;
    while (lo < hi) {
        int md = (lo+hi)>>1;
        if (v[md] <= y) lo = md+1; else hi = md;
    }
    int R = lo;
    return R - L;
}

int query(int node, int l, int r, int ql, int qr, int x, int y) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return count_in_node(node, x, y);
    }
    int mid = (l+r)>>1;
    return query(node<<1, l, mid, ql, qr, x, y)
         + query(node<<1|1, mid+1, r, ql, qr, x, y);
}

int main(){
    scanf("%d", &n);
    a = malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    seg = malloc(4*(n+1)*sizeof(int*));
    sz  = malloc(4*(n+1)*sizeof(int));
    build(1,1,n);
    scanf("%d", &m);
    while (m--) {
        int l,r,x,y;
        scanf("%d %d %d %d", &l,&r,&x,&y);
        printf("%d\n", query(1,1,n,l,r,x,y));
    }
    return 0;
}