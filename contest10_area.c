#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, q;
    scanf("%d %d", &n, &q);

    long long *a      = (long long int *)malloc((n+2) * sizeof(long long));
    long long *diff_c2 = (long long int *) calloc(n+3, sizeof(long long));
    long long *diff_c1 = (long long int *) calloc(n+3, sizeof(long long));
    long long *diff_c0 = (long long int *) calloc(n+3, sizeof(long long));
    long long *x_ = (long long int *)malloc((q+2) * sizeof(long long));
    long long *l_ = (long long int *)malloc((q+2) * sizeof(long long));
    long long *p = (long long int *)malloc((q+2) * sizeof(long long));
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }

    for(int _ = 0; _ < q; _++){
        scanf("%lld %lld", &x_[_], &l_[_]);
        p[_] = l_[_] + x_[_];
    }
    for(int _ = 0; _ < q; _++){
        
        long long x = x_[_];
        long long l = l_[_];
        long long P = p[_];
        diff_c2[x]     +=  1;
        diff_c2[x+l]   -=  1;
        diff_c1[x]     += -2 * P;
        diff_c1[x+l]   -= -2 * P;
        diff_c0[x]     +=  P * P;
        diff_c0[x+l]   -=  P * P;
    }

    long long c2 = 0, c1 = 0, c0 = 0;
    for(int i = 1; i <= n; i++){
        c2 += diff_c2[i];
        c1 += diff_c1[i];
        c0 += diff_c0[i];

        a[i] += c2 * (long long)i * i
              + c1 * (long long)i
              + c0;
    }

    for(int i = 1; i <= n; i++){
        printf("%lld ", a[i]);
    }
}