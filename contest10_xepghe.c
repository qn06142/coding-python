#include <stdio.h>
#include <stdlib.h>

#define MAXN 200000

static int fw[MAXN+5];
int NFW;

void fenw_update(int pos, int v) {
    while (pos <= NFW) {
        if (fw[pos] < v) fw[pos] = v;
        pos += pos & -pos;
    }
}

int fenw_query(int pos) {
    int res = 0;
    while (pos > 0) {
        if (fw[pos] > res) res = fw[pos];
        pos -= pos & -pos;
    }
    return res;
}

int main(){
    int n;
    if (scanf("%d", &n)!=1) return 0;

    static int l[MAXN], r[MAXN];
    static int prev_limit[MAXN], next_free[MAXN];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &l[i], &r[i]);
        prev_limit[i] = i - l[i] - 1;
        next_free[i]  = i + r[i] + 1;
    }

    static int head[MAXN+2], next_j[MAXN];
    for(int t = 0; t <= n; t++) head[t] = -1;
    for(int j = 0; j < n; j++){
        int t = next_free[j];
        if (t <= n) {
            next_j[j] = head[t];
            head[t] = j;
        }

    }

    NFW = n;
    for(int i = 1; i <= NFW; i++) fw[i] = 0;

    static int dp[MAXN];
    for(int i = 0; i < n; i++){

        for(int j = head[i]; j != -1; j = next_j[j]) {

            fenw_update(j+1, dp[j]);
        }

        int dp_no = (i > 0 ? dp[i-1] : 0);

        int best_before = 0;
        if (prev_limit[i] >= 0) {

            best_before = fenw_query(prev_limit[i] + 1);
        }
        int dp_pick = 1 + best_before;

        dp[i] = (dp_no > dp_pick ? dp_no : dp_pick);
    }

    printf("%d\n", dp[n-1]);
    return 0;
}