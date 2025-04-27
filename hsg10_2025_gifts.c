#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int cmp(const void *a, const void *b) {
    ll aa = *(ll*)a, bb = *(ll*)b;
    if (aa < bb) return -1;
    if (aa > bb) return 1;
    return 0;
}

int main(){
    int n, k;
    ll m;

    if(scanf("%d %lld %d", &n, &m, &k) != 3) return 1;

    ll *prices = (ll*)malloc(n * sizeof(ll));
    for(int i = 0; i < n; i++){
        scanf("%lld", &prices[i]);
    }

    qsort(prices, n, sizeof(ll), cmp);

    ll *p = (ll*)malloc((n + 1) * sizeof(ll));
    ll *h = (ll*)malloc((n + 1) * sizeof(ll));
    p[0] = 0;
    h[0] = 0;
    for(int i = 1; i <= n; i++){
        p[i] = p[i - 1] + prices[i - 1];

        h[i] = h[i - 1] + prices[i - 1] / 2;
    }

    int can_buy = 0;
    ll cost;

    int lo = 0, hi = n, ans = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(mid <= k){
            cost = h[mid];
        } else {
            cost = p[mid - k] + (h[mid] - h[mid - k]);
        }
        if(cost <= m){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", ans);
}