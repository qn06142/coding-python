#include<bits/stdc++.h>
using namespace std;
long long a[100000];
bool check(long long mid, int n, int k) {
    long long pieces = 0;
    for(int i=0; i<n; i++){
        pieces += a[i] / mid;
    }
    return pieces >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    long long max_a = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }

    long long low = 1, high = max_a + 1;
    while(high - low > 1){
        long long mid = low + (high - low) / 2;
        if(check(mid, n, k)){
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << low << "\n";

    return 0;
}
