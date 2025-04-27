#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define L 62  

bool feasible(unsigned long long n, unsigned long long mask) {

    bool dp[L+1][4] = { { false } };
    dp[0][0] = true;

    for (int i = 0; i < L; i++) {
        int bit_n = (n >> i) & 1;
        int forced = (mask >> i) & 1; 
        for (int carry = 0; carry < 4; carry++) {
            if (!dp[i][carry])
                continue;
            if (forced) {

                int total = 3 + carry;
                int bit_res = total & 1;
                int car = total >> 1;
                if (bit_res == bit_n)
                    dp[i+1][car] = true;
            } else {

                for (int s = 0; s < 4; s++) {
                    int total = s + carry;
                    int bit_res = total & 1;
                    int car = total >> 1;
                    if (bit_res == bit_n)
                        dp[i+1][car] = true;
                }
            }
        }
    }

    return dp[L][0];
}

unsigned long long solve(unsigned long long n) {
    unsigned long long ans = 0;

    for (int i = L-1; i >= 0; i--) {
        unsigned long long candidate = ans | (1ULL << i);
        if (feasible(n, candidate)) {
            ans = candidate;
        }
    }
    return ans;
}

int main(){
    unsigned long long n;
    scanf("%llu", &n);
    printf("%llu\n", solve(n));
    return 0;
}