#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int n, k, p;
int people[1000], cakes[2000];

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int can_assign(int max_time) {
    int i = 0, j = 0;
    while (i < n && j < k) {
        if (abs(people[i] - cakes[j]) + abs(cakes[j] - p) <= max_time) {
            i++; 
        }
        j++; 
    }
    return i == n; 
}

int main() {

    scanf("%d %d %d", &n, &k, &p);
    for (int i = 0; i < n; i++) scanf("%d", &people[i]);
    for (int i = 0; i < k; i++) scanf("%d", &cakes[i]);

    qsort(people, n, sizeof(int), cmp);
    qsort(cakes, k, sizeof(int), cmp);

    int left = 0, right = INF, ans = INF;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (can_assign(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}