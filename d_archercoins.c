#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
#define MAXN 100005

typedef long long ll;

int n;
int t[MAXN], t_comp[MAXN];
ll bit_count[MAXN], bit_sum[MAXN];

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int lower_bound(int *arr, int size, int value) {
    int left = 0, right = size - 1, ans = size;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= value) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans + 1; 
}

void update(ll *bit, int idx, ll val) {
    while (idx < MAXN) {
        bit[idx] = (bit[idx] + val) % MOD;
        idx += idx & -idx;
    }
}

ll query(ll *bit, int idx) {
    ll res = 0;
    while (idx > 0) {
        res = (res + bit[idx]) % MOD;
        idx -= idx & -idx;
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        t_comp[i] = t[i];
    }

    qsort(t_comp + 1, n, sizeof(int), cmp);
    int m = 1;
    for (int i = 2; i <= n; i++) {
        if (t_comp[i] != t_comp[m]) {
            t_comp[++m] = t_comp[i];
        }
    }

    ll total_fee = 0;
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(t_comp + 1, m, t[i]);
        ll less_count = query(bit_count, idx - 1);
        ll greater_sum = (query(bit_sum, m) - query(bit_sum, idx - 1) + MOD) % MOD;
        ll fee = (less_count + (greater_sum - (1LL * t[i] * (i - 1 - less_count)) % MOD + MOD) % MOD) % MOD;
        total_fee = (total_fee + fee) % MOD;

        update(bit_count, idx, 1);
        update(bit_sum, idx, t[i]);
    }

    printf("%lld\n", total_fee);
    return 0;
}