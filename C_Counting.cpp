#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
const int MAX_N = 100005;

int block_size, cnt[MAX_N], a[MAX_N];

struct Query {
    int l, r, idx;
    bool operator<(const Query &other) const {
        int block_own = l / block_size;
        int block_other = other.l / block_size;
        if (block_own != block_other)
            return block_own < block_other;
        return r < other.r;
    }
};

int result[MAX_N];
vector<int> answers;

void add(int x, int &uniqueCount) {
    cnt[x]++;
    if (cnt[x] == 1) uniqueCount++;
    if (cnt[x] == 2) uniqueCount--;
}

void remove(int x, int &uniqueCount) {
    cnt[x]--;
    if (cnt[x] == 1) uniqueCount++;
    if (cnt[x] == 0) uniqueCount--;
}

int main() {
    int n, q;
    cin >> n;
    block_size = sqrt(n);
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cin >> q;
    vector<Query> queries(q);
    
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; queries[i].r--; // Chuyển về chỉ số 0-based
        queries[i].idx = i;
    }
    
    sort(queries.begin(), queries.end());
    
    int cur_l = 0, cur_r = -1, uniqueCount = 0;
    
    for (const auto& query : queries) {
        while (cur_r < query.r) add(a[++cur_r], uniqueCount);
        while (cur_r > query.r) remove(a[cur_r--], uniqueCount);
        while (cur_l < query.l) remove(a[cur_l++], uniqueCount);
        while (cur_l > query.l) add(a[--cur_l], uniqueCount);
        
        result[query.idx] = 0;
        for (int i = query.l; i <= query.r; ++i) {
            if (cnt[a[i]] == 1) {
                result[query.idx] = a[i];
                break;
            }
        }
    }
    
    for (int i = 0; i < q; ++i)
        cout << result[i] << endl;

    return 0;
}
