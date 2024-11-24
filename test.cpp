#include<bits/stdc++.h>
using namespace std;

bool check(int mid, int n, int L, int h[]){
    long long wood = 0;
    for(int i=0; i<n; i++){
        if(h[i] > mid){
            wood += h[i] - mid;
        }
    }
    return wood >= L;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, L;
    cin >> n >> L;
    int h[n];
    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    int low = 0, high = 1e9;
    while(high - low > 1){
        int mid = (low + high) / 2;
        if(check(mid, n, L, h)){
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << low << "\n";

    return 0;
}

