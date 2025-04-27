#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 1000
#define INF 1000000000

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main(){
    int n, k;
    if(scanf("%d %d", &n, &k) != 2) return 1;

    int *b = (int *)malloc(n * sizeof(int));
    int *c = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &c[i]);
    }

    int dp_level[MAX_LEVEL + 1];
    for (int i = 1; i <= MAX_LEVEL; i++){
        dp_level[i] = INF;
    }
    dp_level[1] = 0;  

    for (int a = 1; a <= MAX_LEVEL; a++){
        if (dp_level[a] == INF) continue;
        for (int x = 1; x <= a; x++){
            int inc = a / x;  
            int new_level = a + inc;

            if (new_level <= MAX_LEVEL) {
                dp_level[new_level] = min(dp_level[new_level], dp_level[a] + 1);
            }
        }
    }

    int *dp_knap = (int *)malloc((k + 1) * sizeof(int));
    for (int j = 0; j <= k; j++){
        dp_knap[j] = 0;
    }

    for (int i = 0; i < n; i++){
        int cost = dp_level[b[i]];
        if (cost > k) continue; 
        for (int j = k; j >= cost; j--){
            int candidate = dp_knap[j - cost] + c[i];
            if (candidate > dp_knap[j])
                dp_knap[j] = candidate;
        }
    }

    printf("%d\n", dp_knap[k]);

    free(b);
    free(c);
    free(dp_knap);

    return 0;
}