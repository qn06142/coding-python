#include<bits/stdc++.h>

using namespace std;
long long a[(int) 1e6 + 5], pref[(int) 1e6 + 5], tree[(int) 8e6 + 5];
vector<long long> compress;
void build() {
    for(int i = 0; i <= 1e6; i++) tree[i] = 0;
}
void update(long long x, long long y, int node = 1, int l = 1, int r = 2e6) {
    if(l == r) tree[node] += y;
    else {
        int mid = (l + r) / 2;
        if(x > mid) {
            update(x, y, node * 2 + 1, mid + 1, r);
        } else {
            update(x, y, node * 2, l, mid);
        }
        tree[node] = tree[node * 2]  + tree[node * 2 + 1];
    }
}
long long getval(long long x, long long y, int node = 1, int l = 1, int r = 2e6) {
    if(x > r or y < l) return 0;
    if(x <= l and y >= r) {
        return tree[node];
    }
    int mid = (l + r) / 2;
    long long l_ = getval(x, y, node * 2, l, mid);
    long long r_ = getval(x, y, node * 2 + 1, mid + 1, r);
    return l_ + r_;
}

int main() {
    int n, p;
    cin >> n;
    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    build();
    cin >> p;
    //same as pref[i - 1] - p * i + p <= pref[j] - p * j 
    //
    int count = 0;
    for (int i = 1; i <= n; i++) {
        compress.push_back(pref[i - 1] - p * i + p);
        compress.push_back(pref[i] - p * i);
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for(int i = 1; i <= n; i++) {
        long long u = lower_bound(compress.begin(), compress.end(), pref[i - 1] - p * i + p) - compress.begin() + 1;
        long long v = lower_bound(compress.begin(), compress.end(), pref[i] - p * i) - compress.begin() + 1;
        //cout << u << " " << v << endl;
        update(u, 1);
        count += getval(1, v);
    }

    cout << count << endl;
}