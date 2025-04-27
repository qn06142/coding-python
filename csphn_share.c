#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef long long ll;

typedef struct {
    int idx;    
    ll val;     
} Pair;

int cmp(const void *a, const void *b) {
    Pair *p = (Pair *)a;
    Pair *q = (Pair *)b;
    if (p->val < q->val) return -1;
    else if (p->val > q->val) return 1;
    else return 0;
}

int upper_bound(ll *arr, int n, ll key) {
    int lo = 0, hi = n;
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(arr[mid] <= key) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main(){
    int n, i;
    ll m;
    if(scanf("%d %lld", &n, &m) != 2)
        return 1;

    ll *a = (ll *)malloc(n * sizeof(ll));
    if(a == NULL) return 1;

    ll total = 0;
    ll min_a = 10000000000LL; 
    ll max_a = 0;
    for(i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        total += a[i];
        if(a[i] < min_a) min_a = a[i];
        if(a[i] > max_a) max_a = a[i];
    }

    if(m > total){
        printf("-1");
        free(a);
        return 0;
    }

    ll ans = (min_a < (m / n) ? min_a : (m / n));

    Pair *pairs = (Pair *)malloc(n * sizeof(Pair));
    for(i = 0; i < n; i++){
        pairs[i].idx = i;
        pairs[i].val = a[i];
    }
    qsort(pairs, n, sizeof(Pair), cmp);

    ll *sorted = (ll *)malloc(n * sizeof(ll));
    ll *prefix = (ll *)malloc((n+1) * sizeof(ll));
    prefix[0] = 0;
    for(i = 0; i < n; i++){
        sorted[i] = pairs[i].val;
        prefix[i+1] = prefix[i] + sorted[i];
    }

    ll lo = 0, hi = max_a, ansD = hi;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        ll cap = ans + mid;
        int pos = upper_bound(sorted, n, cap);
        ll h_val = prefix[pos] + (ll)(n - pos) * cap;

        if((ll)n * ans <= m && m <= h_val){
            ansD = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    ll R = m - (ll)n * ans;
    ll *contrib = (ll *)malloc(n * sizeof(ll));
    for(i = 0; i < n; i++){
        contrib[i] = ans;
    }

    for(i = 0; i < n && R > 0; i++){
        ll add_possible = (ans + ansD < a[i] ? ans + ansD : a[i]) - ans;
        ll add = (R < add_possible ? R : add_possible);
        contrib[i] += add;
        R -= add;
    }

    if(R != 0){
        printf("-1");
    } else {
        for(i = 0; i < n; i++){
            printf("%lld ", contrib[i]);
        }
    }

    return 0;
}