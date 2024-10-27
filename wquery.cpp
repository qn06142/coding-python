#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100000;
const int MAXA = 1000000;

struct Query {
    int L, R, idx;
};

int a[MAXN];
Query queries[MAXN];
long long result[MAXN];
int freq[MAXA + 1];
long long current_sum = 0;

void add(int x) {
    current_sum -= 1LL * freq[x] * freq[x] * x;
    freq[x]++;
    current_sum += 1LL * freq[x] * freq[x] * x;
}

void remove(int x) {
    current_sum -= 1LL * freq[x] * freq[x] * x;
    freq[x]--;
    current_sum += 1LL * freq[x] * freq[x] * x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int block_size = sqrt(n);

    for (int i = 0; i < q; ++i) {
        int L, R;
        cin >> L >> R;
        queries[i] = {L, R, i};
    }

    sort(queries, queries + q, [block_size](const Query& x, const Query& y) {
        if (x.L / block_size != y.L / block_size) {
            return x.L / block_size < y.L / block_size;
        }
        return x.R < y.R;
    });

    int L = 0, R = -1;
    for (int i = 0; i < q; ++i) {
        while (R < queries[i].R) add(a[++R]);
        while (R > queries[i].R) remove(a[R--]);
        while (L < queries[i].L) remove(a[L++]);
        while (L > queries[i].L) add(a[--L]);
        result[queries[i].idx] = current_sum;
    }

    for (int i = 0; i < q; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}
