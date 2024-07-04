#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long
class FenwickTree {
public:
    FenwickTree(int size) : data(size + 1, 0) {}
    
    void update(int index, int delta) {
        while (index < data.size()) {
            data[index] += delta;
            index += index & -index;
        }
    }
    
    long long query(int index) const {
        long long sum = 0;
        while (index > 0) {
            sum += data[index];
            index -= index & -index;
        }
        return sum;
    }
    
private:
    vector<long long> data;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> queries(N);
    vector<int> values;
    values.reserve(N);

    for (int i = 0; i < N; ++i) {
        int ai, bi;
        cin >> ai >> bi;
        queries[i] = {ai, bi};
        values.push_back(ai);
    }

    // Number compression
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    unordered_map<int, int> compressed;

    for (int i = 0; i < values.size(); ++i) {
        compressed[values[i]] = i + 1;
    }

    FenwickTree fenwickTree(values.size());

    for (int i = 0; i < N; ++i) {
        int ai = queries[i].first;
        int bi = queries[i].second;
        fenwickTree.update(compressed[ai], bi);
    }

    int left = 1, right = values.size(), answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (fenwickTree.query(mid) >= K) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // Convert compressed index back to original value
    for (const auto &pair : compressed) {
        if (pair.second == answer) {
            cout << pair.first << endl;
            break;
        }
    }

    return 0;
}
