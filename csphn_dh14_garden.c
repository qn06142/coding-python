#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N 20
#define PI 3.141592653589793

typedef struct {
    double x, y;
} Point;

double cross(Point a, Point b, Point c) {
    return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
}

int cmp(const void *a, const void *b) {
    Point *p = (Point *)a;
    Point *q = (Point *)b;
    if (p->x < q->x) return -1;
    if (p->x > q->x) return 1;
    if (p->y < q->y) return -1;
    if (p->y > q->y) return 1;
    return 0;
}

int convex_hull(Point pts[], int n, Point hull[]) {
    if(n == 0) return 0;
    qsort(pts, n, sizeof(Point), cmp);
    int k = 0;

    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }

    int t = k + 1;
    for (int i = n - 2; i >= 0; i--) {
        while (k >= t && cross(hull[k-2], hull[k-1], pts[i]) <= 0) k--;
        hull[k++] = pts[i];
    }
    if(n > 1) k--; 
    return k;
}

double perimeter(Point hull[], int m) {
    if(m <= 1) return 0;
    double per = 0;
    for (int i = 0; i < m; i++) {
        int j = (i + 1) % m;
        double dx = hull[i].x - hull[j].x;
        double dy = hull[i].y - hull[j].y;
        per += sqrt(dx * dx + dy * dy);
    }
    return per;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int d, n, r;
        scanf("%d %d %d", &d, &n, &r);
        Point trees[MAX_N];
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &trees[i].x, &trees[i].y);
        }

        int best = 0;
        int total = 1 << n; 

        for (int mask = 1; mask < total; mask++) {
            int count = __builtin_popcount(mask);

            if(count <= best) continue;

            Point subset[MAX_N];
            int idx = 0;
            for (int i = 0; i < n; i++) {
                if(mask & (1 << i))
                    subset[idx++] = trees[i];
            }

            double required;
            if(count == 1) {

                required = 2 * PI * r;
            } else if(count == 2) {

                double dx = subset[0].x - subset[1].x;
                double dy = subset[0].y - subset[1].y;
                double L = sqrt(dx * dx + dy * dy);
                required = 2 * L + 2 * PI * r;
            } else {

                Point hull[MAX_N];
                int m = convex_hull(subset, count, hull);
                double per = perimeter(hull, m);
                required = per + 2 * PI * r;
            }

            if(required <= d + 1e-9) {
                if(count > best)
                    best = count;
            }
        }

        printf("%d\n", best);
    }
    return 0;
}