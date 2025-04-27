#pragma GCC optimize("O3")
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int w, value;
} Item;

typedef struct {
    int c;
    int used;
} Backpack;

int compare_items(const void *a, const void *b) {
    return ((Item*)b)->value - ((Item*)a)->value;
}

int compare_backpacks(const void *a, const void *b) {
    return ((Backpack*)a)->c - ((Backpack*)b)->c;
}

int find_backpack(Backpack bp[], int m, int w) {
    int left = 0, right = m - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (bp[mid].c >= w) {
            if (mid == 0 || bp[mid - 1].c < w) {
                return mid;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

long long calc(Item items[], int n, Backpack bp[], int m) {
    qsort(items, n, sizeof(Item), compare_items);
    qsort(bp, m, sizeof(Backpack), compare_backpacks);
    
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int idx = find_backpack(bp, m, items[i].w);
        if (idx != -1) {
            ans += items[i].value;
            bp[idx].used = 1;
            for (int j = idx; j < m - 1; j++) {
                bp[j] = bp[j + 1];
            }
            m--;
        }
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Item items[n];
    Backpack bp[m];
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].w, &items[i].value);
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &bp[i].c);
        bp[i].used = 0;
    }
    
    long long ans = calc(items, n, bp, m);
    printf("%lld\n", ans);
    
    return 0;
}
