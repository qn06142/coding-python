#include <iostream>
#include <vector>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int N, K, Q;
vector<int> a;
vector<int> f;

void prepare_f() {
    f.assign(K + 1, 0);
    f[0] = 1;
    for (int value : a) {
        for (int j = K; j >= value; --j) {
            f[j] = (f[j] + f[j - value]) % MOD;
        }
    }
}

int process_query(vector<int> f_copy, int xi, int yi, int si) {
    int s = si - a[xi] - a[yi];
    for (int j = a[xi]; j <= K; j++) {
        f_copy[j] = (f_copy[j] - f_copy[j - a[xi]] + MOD) % MOD;
    }
    for (int j = a[yi]; j <= K; j++) {
        f_copy[j] = (f_copy[j] - f_copy[j - a[yi]] + MOD) % MOD;
    }
    int result = 0;
    for (int i = 0; i <= s; ++i) {
        result = (result + f_copy[i]) % MOD;
    }
    return result;
}

signed main() {
    cin >> N >> K >> Q;
    a.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    vector<pair<pair<int, int>, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        int xi, yi, si;
        cin >> xi >> yi >> si;
        queries[i] = {{xi - 1, yi - 1}, si};
    }

    prepare_f();

    for (const auto& query : queries) {
        int xi = query.first.first;
        int yi = query.first.second;
        int si = query.second;
        vector<int> f_copy = f; // Copy the array
        int result = process_query(f_copy, xi, yi, si);
        cout << result << endl;
    }

    return 0;
}
