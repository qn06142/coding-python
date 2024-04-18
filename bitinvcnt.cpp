#include<iostream>
#include<cstring>
#define maxn (int) 1e6 + 5
using namespace std;
int n;

long long seq[4 * maxn], a[maxn];
void update(int x, int y, int node = 1, int l = 1, int r = 1e6) {
    if(l == r) {
        seq[node] += y;

    } else {
        int mid = (l + r) / 2;
        if(x > mid) {
            //go right
            update(x, y, node * 2 + 1, mid + 1, r);
        } else {
            //go left
            update(x, y, node * 2, l, mid);
        }
        seq[node] = seq[node * 2] + seq[node * 2 + 1];
    }
}
long long getsum(int x, int y, int node = 1, int l = 1, int r = 1e6) {
    //get sum from x to y
    if(x > r or y < l) {
        //not intersect
        return 0;
    } else {
        if(x <= l and y >= r) {
            //contains all
            return seq[node];
        }
        //intersect only
        int mid = (l + r) / 2;
        long long L = getsum(x, y, node * 2, l, mid);
        long long R = getsum(x, y, node * 2 + 1, mid + 1, r);
        return L + R;
    }
}
int main() {
    //http://csloj.ddns.net/problem/512
    cin >> n;
    long long ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i + 1];
    for(int i = 1; i <= n; i++) {
        update(a[i], 1);
        ans += getsum(a[i] + 1, 1e6);
    }
    cout << ans;

}