#include<iostream>
using namespace std;
const int maxn = (int) 6e3 + 5;

int a[maxn], dp[maxn];

int main() {
    int n, l;
    cin >> n >> l;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        dp[i] = l + 1;
        int j = i, s = a[i];
        while(j > 0 and s <= l) {
            dp[i]  = min(dp[i], max(dp[j - 1], ;l - s));
            s += a[--j];
        }
    }
    cout << dp[n];
}