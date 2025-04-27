#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    #define int long long
    int *a = malloc(sizeof(int) * n);
    int *diff = calloc(n + 1, sizeof(long long)); 

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    while (m--) {
        int t, l, r, x;
        scanf("%lld %lld %lld %lld", &t, &l, &r, &x);
        l--, r--; 

        diff[l] += (t ? x : -x);
        diff[r + 1] -= (t ? x : -x);
    }

    int delta = 0;
    for (int i = 0; i < n; i++) {
        delta += diff[i]; 
        a[i] += delta;    
        printf("%lld ", a[i]);
    }
}