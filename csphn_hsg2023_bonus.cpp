#include<vector>
#include<algorithm>
#include<climits>
#include<iostream>
#include<numeric>
#include<cmath>
using namespace std;
const int maxn = 4e5 + 5;
int a[maxn];
long long suf[maxn], suf1[maxn];
long long pref[maxn], sparsemax[20][maxn], sparsemin[20][maxn];
int getmax(int l,int r) {
    int k = __lg(r - l + 1);
    return max(sparsemax[k][l], sparsemax[k][r - (1 << k) + 1]);
}
int getmin(int l,int r) {
    int k = __lg(r - l + 1);
    return min(sparsemin[k][l], sparsemin[k][r - (1 << k) + 1]);
}
int n, k;
long long bsearch(int i) {
    int l = i, r = n;
    int mid, ans = 0;
    while(l <= r) {
        mid = (l + r) / 2;
        if(abs(getmax(i, mid) - getmin(i, mid)) <= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
long long max_gift_value() {
    long long max_value = 0;
    for (int i = 1; i <= n; ++i) {
        suf[i] = pref[bsearch(i)] - pref[i - 1];
        //cout << i << " " << bsearch(i) << endl;;
    }
    for(int i = n; i >= 1; i--) suf1[i] = max(suf1[i + 1], suf[i]);
    for (int i = 1; i <= n; ++i) {
        int tmp = bsearch(i);
        max_value = max(max_value, (long long) pref[tmp] - pref[i - 1] + suf1[tmp + 1]);
    }

    return max_value;
}

signed main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        sparsemax[0][i] = a[i];
        sparsemin[0][i] = a[i];
    }
    for(int j = 1; j <= ceil(__lg(n)); j++) {
        for(int i = 1; i + (1 << j ) - 1 <= n; i++) {
            sparsemax[j][i] = max(sparsemax[j - 1][i], sparsemax[j - 1][i + (1 << (j - 1))]);
            sparsemin[j][i] = min(sparsemin[j - 1][i], sparsemin[j - 1][i + (1 << (j - 1))]);
        }
    }
    cout << max_gift_value();

    return 0;
}
