#include <stdio.h>
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

int upper_bound(int arr[], int n, int target) {
    int left = 0, right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int lower_bound(int arr[], int n, int target) {
    int left = 0, right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int a[(int) 1e5 + 5];
int b[(int) 1e5 + 5];

int main() {
    int n, d, t;
    scanf("%d %d %d", &n, &d, &t);
    int maxt = 0;

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxt = max(maxt, a[i]);
    }

    int cur = t;
    int i = 0;
    while (cur <= maxt) {
        i++;
        b[i] = cur;
        cur += d;
    }

    for(int i_ = 1; i_ <= n; i_++) {
        printf("%d ", lower_bound(b + 1, i, a[i_]) + 1);
    }

    return 0;
}