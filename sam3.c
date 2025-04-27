#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

static inline long long modfix(long long x) {
    x %= MOD;
    if(x < 0) x += MOD;
    return x;
}

int main(){
    int n, p, q, r;
    if(scanf("%d %d %d %d", &n, &p, &q, &r) != 4) return 1;

    int L[3];
    L[0] = p; L[1] = q; L[2] = r;

    long long *dp = (long long*)malloc((n+1) * sizeof(long long));
    dp[0] = 1; 

    long long *P0 = (long long*)calloc(n+1, sizeof(long long));
    long long *P1 = (long long*)calloc(n+1, sizeof(long long));
    long long *P2 = (long long*)calloc(n+1, sizeof(long long));

    P0[0] = P1[0] = P2[0] = 0;

    for (int i = 1; i <= n; i++){
        long long a0, a1, a2; 
        long long S0_prev, S1_prev, S2_prev; 

        if(i == 1){
            a0 = 1; a1 = 1; a2 = 1;
        } else {
            int idx = i - 1;

            if(idx < L[0])
                S0_prev = P0[idx];
            else {
                S0_prev = modfix(P0[idx] - P0[idx - L[0]]);
            }
            a0 = modfix(dp[i-1] - S0_prev);

            idx = i - 1;
            if(idx < L[1])
                S1_prev = P1[idx];
            else {
                S1_prev = modfix(P1[idx] - P1[idx - L[1]]);
            }
            a1 = modfix(dp[i-1] - S1_prev);

            idx = i - 1;
            if(idx < L[2])
                S2_prev = P2[idx];
            else {
                S2_prev = modfix(P2[idx] - P2[idx - L[2]]);
            }
            a2 = modfix(dp[i-1] - S2_prev);
        }

        P0[i] = modfix(P0[i-1] + a0);
        P1[i] = modfix(P1[i-1] + a1);
        P2[i] = modfix(P2[i-1] + a2);

        long long S0, S1, S2;
        if(i < L[0])
            S0 = P0[i];
        else {
            S0 = modfix(P0[i] - P0[i - L[0]]);
        }
        if(i < L[1])
            S1 = P1[i];
        else {
            S1 = modfix(P1[i] - P1[i - L[1]]);
        }
        if(i < L[2])
            S2 = P2[i];
        else {
            S2 = modfix(P2[i] - P2[i - L[2]]);
        }
        dp[i] = modfix(S0 + S1 + S2);
    }

    printf("%lld\n", dp[n] % MOD);
}