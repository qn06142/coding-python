#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007LL

int cmp(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if(x < y) return -1;
    else if(x > y) return 1;
    else return 0;
}

int main(){
    int n;
    if(scanf("%d", &n) != 1) return 1;

    long long *A = (long long*)malloc(n * sizeof(long long));
    if(A == NULL) return 1;

    for(int i = 0; i < n; i++){
        scanf("%lld", &A[i]);
    }

    qsort(A, n, sizeof(long long), cmp);

    long long res = 0;

    for (int i = 0; i < n; i++){
        res = (res + (A[i] % MOD) * (A[i] % MOD)) % MOD;
    }

    long long dp = 0;
    if(n > 1){
        dp = A[0] % MOD;  
        for (int j = 1; j < n; j++){

            res = (res + (A[j] % MOD) * dp) % MOD;

            dp = (2 * dp + A[j]) % MOD;
        }
    }

    printf("%lld", res);

    free(A);
    return 0;
}