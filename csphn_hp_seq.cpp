#include<bits/stdc++.h>
using namespace std;
int a[(int) 1e5 + 5];
#define maxn (int) 1e5 + 5
long long seq[4 * maxn];
void build(int node = 1, int l = 1, int r = n) {
    if(l == r) {
        seq[node] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(node * 2 + 1, mid + 1, r);
        build(node * 2, l, mid);
        seq[node] = seq[node * 2] + seq[node * 2 + 1];
    }
}
void update(int x, int y, int node = 1, int l = 1, int r = n) {
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
long long getsum(int x, int y, int node = 1, int l = 1, int r = n) {
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
long long countSub(int n)
{
	for(int i = 0; i < n; i++) {
		update(a[i], getsum(0, a[i] - 1));
	}
	return getsum(0, (int) 1e9);
}

int main()
{

	build()
    int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> compress(a, a + n);
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(compress.begin(), compress.end(), a[i]) - compress.begin();
    }
	cout << countSub(n);
	return 0;
}