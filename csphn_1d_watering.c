#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int L, R; 
} Interval;

int cmp(const void *a, const void *b) {
    Interval *ia = (Interval *)a;
    Interval *ib = (Interval *)b;
    if (ia->L == ib->L)
        return ib->R - ia->R; 
    return ia->L - ib->L;
}

int main() {
    int n;
    scanf("%d", &n);

    int *h = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    int *L = (int *)malloc(n * sizeof(int));
    L[0] = 0;
    for (int i = 1; i < n; i++) {
        if (h[i-1] <= h[i])
            L[i] = L[i-1];
        else
            L[i] = i;
    }

    int *R = (int *)malloc(n * sizeof(int));
    R[n-1] = n-1;
    for (int i = n - 2; i >= 0; i--) {
        if (h[i+1] <= h[i])
            R[i] = R[i+1];
        else
            R[i] = i;
    }

    Interval *intervals = (Interval *)malloc(n * sizeof(Interval));
    for (int i = 0; i < n; i++) {
        intervals[i].L = L[i];
        intervals[i].R = R[i];
    }

    qsort(intervals, n, sizeof(Interval), cmp);

    int count = 0;
    int current = 0; 
    int i = 0;
    while (current < n) {
        int maxR = -1;

        while (i < n && intervals[i].L <= current) {
            if (intervals[i].R > maxR)
                maxR = intervals[i].R;
            i++;
        }

        if (maxR < current) {
            printf("-1\n");
            return 0;
        }
        count++;
        current = maxR + 1;
    }

    printf("%d\n", count);

    free(h);
    free(L);
    free(R);
    free(intervals);

    return 0;
}