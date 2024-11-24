#include<bits/stdc++.h>

using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
int a[(int) 2e5 + 5], divs[(int) 1e7 + 5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sqrt(a[i]); j++) {
            if(a[i] % j == 0) {
                //cout << a[i] << ' ' << a[i] / j  << ' ' << j << endl;;
                
                divs[j]++;
                if(a[i] / j!= j) 
                divs[a[i] / j]++;
            }
        }
    }
    for(int i = 1e7; i >= 1; i--) {
        if(divs[i] > 1) {
            cout << i;
            return 0;
        }
    }
}