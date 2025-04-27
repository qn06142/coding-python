#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

typedef struct {
    int x1, y1, x2, y2;
} Rect;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int calc(Rect *rects, int *subset, int k) {
    int x1 = rects[subset[0]].x1;
    int y1 = rects[subset[0]].y1;
    int x2 = rects[subset[0]].x2;
    int y2 = rects[subset[0]].y2;

    for (int i = 1; i < k; i++) {
        x1 = max(x1, rects[subset[i]].x1);
        y1 = max(y1, rects[subset[i]].y1);
        x2 = min(x2, rects[subset[i]].x2);
        y2 = min(y2, rects[subset[i]].y2);
    }

    if (x1 >= x2 || y1 >= y2)
        return 0;

    return (x2 - x1) * (y2 - y1);
}

int main() {
    int n;
    scanf("%d", &n);
    Rect rects[MAX_N];

    for (int i = 0; i < n; i++)
        scanf("%d %d %d %d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);

    int total = 0;
    int subset[MAX_N];

    for (int mask = 1; mask < (1 << n); mask++) {
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j))
                subset[k++] = j;
        }

        int area = calc(rects, subset, k);
        if (k % 2 == 1)
            total += area;
        else
            total -= area;
    }

    printf("%d\n", total);
    return 0;
}
