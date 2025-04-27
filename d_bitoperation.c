#include <stdio.h>
#include <stdlib.h>

#define INF (1LL << 60)

int main(){
    long long n;
    scanf("%lld", &n);

    if(n == 0) {
        printf("0\n");
        return 0;
    }

    int m = 0;
    int bits[32];
    long long temp = n;
    while(temp > 0){
        bits[m] = temp & 1;
        m++;
        temp >>= 1;
    }

    long long c[32];
    c[0] = 1;
    for(int i = 1; i < m; i++){
        c[i] = 2 * c[i-1] + 1;
    }

    long long dp[32][2];

    if(bits[0] == 0){
        dp[0][0] = 0;
        dp[0][1] = 1; 
    } else { 
        dp[0][1] = 0;
        dp[0][0] = 1; 
    }

    for(int i = 1; i < m; i++){
        if(bits[i] == 1){

            long long candidate1 = dp[i-1][1] + 1 + c[i-1];
            long long candidate2 = dp[i-1][0] + c[i-1] + 1 + c[i-1];
            dp[i][0] = candidate1 < candidate2 ? candidate1 : candidate2;

            candidate1 = dp[i-1][1] + c[i-1];
            candidate2 = dp[i-1][0];
            dp[i][1] = candidate1 < candidate2 ? candidate1 : candidate2;
        } else {

            long long candidate1 = dp[i-1][1] + c[i-1];
            long long candidate2 = dp[i-1][0];
            dp[i][0] = candidate1 < candidate2 ? candidate1 : candidate2;

            candidate1 = dp[i-1][1] + 1 + c[i-1];
            candidate2 = dp[i-1][0] + c[i-1] + 1 + c[i-1];
            dp[i][1] = candidate1 < candidate2 ? candidate1 : candidate2;
        }
    }

    printf("%lld\n", dp[m-1][0]);

    return 0;
}