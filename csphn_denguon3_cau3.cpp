#include<iostream>
#include<algorithm>

using namespace std;
int a[(int) 1e5 + 5];

bool check(int k, int x, int n) {
    int curr = x;
    for(int i = 1; i <= n; i++) {
        if(curr - a[i] < 0) {
            curr = x - a[i];
            k -= 1;
        } else {
            curr -= a[i];
        }
        if(k <= 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int k, n;
    cin >> n >> k;
    int max_a = 1;
    long long sum_a = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
        sum_a += a[i];
    }
    int l = max_a, r = sum_a;
    while(l <= r) {
        int mid = (l + r) /2 ;
        if(check(k, mid, n)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}
