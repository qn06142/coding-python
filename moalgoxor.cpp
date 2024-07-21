#include<bits/stdc++.h>
using namespace std;

#define MAXN 100001
#define MAXVAL 1000000
#define int long long
int n, m, k;
int arr[MAXN];
pair<pair<int, int>, int> queries[MAXN];
int answers[MAXN];
int cnt[2 * MAXVAL + 5];
long long res = 0;

void add(int idx) {
    res += cnt[arr[idx] ^ k];
    cnt[arr[idx]]++;
}

void remove(int idx) {
    cnt[arr[idx]]--;
    res -= cnt[arr[idx] ^ k];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] ^= arr[i - 1];
    }
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {{l - 1, r }, i};
    }
    
    int block_size = sqrt(n);
    sort(queries, queries + m, [block_size](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        int block_a = a.first.first / block_size;
        int block_b = b.first.first / block_size;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? a.first.second > b.first.second : a.first.second < b.first.second;
    });
    
    int current_l = 1, current_r = 0;
    memset(cnt, 0, sizeof(cnt));
    
    for (int i = 0; i < m; i++) {
        int l = queries[i].first.first;
        int r = queries[i].first.second;
        int idx = queries[i].second;
        
        while (current_r < r) {
            current_r++;
            add(current_r);
        }
        while (current_r > r) {
            remove(current_r);
            current_r--;
        }
        while (current_l < l) {
            remove(current_l);
            current_l++;
        }
        while (current_l > l) {
            current_l--;
            add(current_l);
        }
        
        answers[idx] = res;
    }
    
    for (int i = 0; i < m; i++) {
        cout << answers[i] << '\n';
    }
    
    return 0;
}
