#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    long long ans = LLONG_MAX;
    // Try all possible values for x0 from 0 to 11.
    for (int x0 = 0; x0 < 12; x0++){
        long long total = x0;  // cost for button 0
        // Compute r_1 = (x0 - a[0]) mod 12 (in the unique number in [0,11])
        int r = ( (x0 - a[0]) % 12 + 12 ) % 12;
        total += r;
        // For knobs 2..n: r_i = (r_{i-1} - a[i]) mod 12
        for (int i = 1; i < n; i++){
            r = ( (r - a[i]) % 12 + 12 ) % 12;
            total += r;
        }
        if (total < ans)
            ans = total;
    }
    
    printf("%lld\n", ans);
    free(a);
    return 0;
}
