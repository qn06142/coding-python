#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int cnt[5] = {0}; 

    for (int i = 0; i < n; ++i) {
        int si;
        scanf("%d", &si);
        cnt[si]++;
    }

    int tables = 0;

    tables += cnt[4];

    int min_13 = cnt[3] < cnt[1] ? cnt[3] : cnt[1];
    tables += cnt[3]; 
    cnt[1] -= min_13;

    tables += cnt[2] / 2;
    cnt[2] %= 2;

    if (cnt[2] == 1) {
        if (cnt[1] >= 2) {
            tables += 1;
            cnt[1] -= 2;
        } else if (cnt[1] == 1) {
            tables += 1;
            cnt[1] -= 1;
        } else {
            tables += 1;
        }
    }

    if (cnt[1] > 0) {
        tables += (cnt[1] + 3) / 4;
    }

    printf("%d\n", tables);

    return 0;
}