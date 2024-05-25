#include<iostream>
#include<algorithm>
#include<map>
#include<numeric>
using namespace std;
int a[(int) 1e6 + 5], b[(int) 1e6 + 5];
int m, n, k;
bool mark[(int) 1e6 + 5];
bool check(int x) {
    for(int i = 1; i <= (int) 1e6 + 5; i++) mark[i] = 0;
    int j = 1;
    int count = 0;
    for(int i = 1; i <= m; i++) {
        while(j <= n and (a[i] - b[j] > x or mark[j])) j++;
        if(j <= n and abs(a[i] - b[j]) <= x) {
            count++;
            mark[j] = 1;
        }
    }
    return count >= k;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + m);
    sort(b + 1, b + 1 + n);
    int l = 1, r = 1e9;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        //cout << check(mid) <<' '<< mid << endl;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}