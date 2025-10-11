// brute_a.cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<int>A(n),B(n),C(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> C[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        bool dom=false;
        for(int j=0;j<n;j++) if(j!=i)
            if(A[j]>A[i] && B[j]>B[i] && C[j]>C[i]) { dom=true; break; }
        if(dom) ++cnt;
    }
    cout<<cnt<<"\n";
}
