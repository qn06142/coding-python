#include<bits/stdc++.h>
using namespace std;

bool check(long long mid, int n, int m, vector<long long> &a) {
    long long containers = 1, sum = 0;
    for(int i=0; i<n; i++){
        if(sum + a[i] > mid){
            sum = a[i];
            containers++;
        } else {
            sum += a[i];
        }
    }
    return containers <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    long long max_a = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }

    long long low = max_a, high = 1e18;
    while(high - low > 1){
        long long mid = low + (high - low) / 2;
        if(check(mid, n, m, a)){
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << high << "\n";

    return 0;
}
