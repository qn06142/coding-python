#include<bits/stdc++.h>
#define ll long long
#define all(v) begin(v), end(v)
#define pi pair<int, int>
#define vi vector<int>
using namespace std;
const int N = 1e5+3;
int n, k, p, a[N*2], b[N*2], c[N*2];

multiset<int> mt;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> p;
    k = min(k, n);
    for(int i = 1; i <= n; i++) cin >> a[i+n-1];
    for(int i = 1; i < n; i++) a[i] = a[n+i];
    for(int i = 1; i <= k; i++){
        b[1] += a[i];
    }
    for(int i = k+1; i < 2*n; i++){
        b[i-k+1] = b[i-k] + a[i] - a[i-k];
    }
    // for(int i = 1; i <= 2*n - k; i++) cout << b[i] << " ";
    // cout << "\n";
    int d = n-k+1;
    for(int i = 1; i <= d; i++){
        mt.insert(b[i]);
    }
    c[1] = *mt.rbegin();
    for(int i = d+1; i <= 2*n-k; i++){
        mt.insert(b[i]);
        mt.erase(mt.find(b[i-d]));
        c[i-d+1] = *mt.rbegin();
    }
    // for(int i = 1; i <= 2*n-k-d+1; i++) cout << c[i] << " ";
    int id = n;
    while(p--){
        char ch; cin >> ch;
        if(ch == '!'){
            id--;
            if(id==0) id=n;
        }
        else cout << c[id] << "\n";
    }
    return 0;
}