#include<bits/stdc++.h>
using namespace std;

bool check(int mid, int n, int k, int a[]){
    int cnt = 1, last = a[0];
    for(int i=1; i<n; i++){
        if(a[i] - last >= mid){
            cnt++;
            last = a[i];
        }
    }
    return cnt >= k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int low = 0, high = 1e9+7;
    while(high - low > 1){
        int mid = (low + high) / 2;
        if(check(mid, n, k, a)){
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << low << "\n";

    return 0;
}
