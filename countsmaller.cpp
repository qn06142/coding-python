#include<bits/stdc++.h>
using namespace std;

int a[(int) 1e5 + 5], b[(int) 1e5 + 5], c[(int) 2e5 + 5];

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < m; j++) {
        cin >> b[j];
    }
    int j = 0;
    for(int i = 0; i < m; i++) {
        while(j < n and a[j] < b[i]) j++;
        c[i] = j;
        cout << c[i] << ' ';
    }
}