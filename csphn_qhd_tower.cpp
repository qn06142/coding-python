#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 1000000;
struct Block { int a, b, h, orig; } blk[MAXN+1];

static long long dp[MAXN+1];
static int  pre_idx[MAXN+1];

static long long bit_val[MAXN+1];
static int       bit_idx[MAXN+1];

inline void bit_update(int i, long long v, int idx) {
    for (; i <= MAXN; i += i & -i) {
        if (bit_val[i] < v) {
            bit_val[i] = v;
            bit_idx[i] = idx;
        }
    }
}

inline pair<long long,int> bit_query(int i) {
    long long mv = 0;
    int midx = -1;
    for (; i > 0; i -= i & -i) {
        if (bit_val[i] > mv) {
            mv   = bit_val[i];
            midx = bit_idx[i];
        }
    }
    return {mv, midx};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &blk[i].a, &blk[i].b, &blk[i].h);
        blk[i].orig = i;
    }

    sort(blk+1, blk+n+1, [](const Block &x, const Block &y){
        if (x.a != y.a) return x.a < y.a;
        if (x.b != y.b) return x.b < y.b;
        return x.h < y.h;
    });

    long long best_total = 0;

    for (int i = 1; i <= n; i++) {

        auto [best_prev, idx_prev] = bit_query(blk[i].a);

        dp[i]      = best_prev + blk[i].h;
        pre_idx[i] = idx_prev;  

        bit_update(blk[i].b, dp[i], i);

        if (dp[i] > best_total) {
            best_total = dp[i];

        }
    }

    printf("%lld\n", best_total);
    return 0;
}