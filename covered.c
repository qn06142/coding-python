#include <stdio.h>

int main() {
    long long T;
    scanf("%lld", &T);
    while (T--) {
        long long x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld", 
              &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);

        long long left1   = (x1 < x2) ? x1 : x2;
        long long right1  = (x1 > x2) ? x1 : x2;
        long long bottom1 = (y1 < y2) ? y1 : y2;
        long long top1    = (y1 > y2) ? y1 : y2;

        long long left2   = (x3 < x4) ? x3 : x4;
        long long right2  = (x3 > x4) ? x3 : x4;
        long long bottom2 = (y3 < y4) ? y3 : y4;
        long long top2    = (y3 > y4) ? y3 : y4;

        long long dx = 0;
        if (left2 > right1)
            dx = left2 - right1;
        else if (left1 > right2)
            dx = left1 - right2;

        long long dy = 0;
        if (top1 < bottom2)
            dy = bottom2 - top1;
        else if (top2 < bottom1)
            dy = bottom1 - top2;

        long long ans = dx * dx + dy * dy;
        printf("%lld\n", ans);
    }
    return 0;
}