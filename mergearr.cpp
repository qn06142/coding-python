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
    
    int i = 0, j = 0, k = 0;
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    
    while(i < n) {
        c[k++] = a[i++];
    }
    
    while(j < m) {
        c[k++] = b[j++];
    }
    
    for(int i = 0; i < n + m; i++) {
        cout << c[i] << ' ';
    }
    
    return 0;
}
