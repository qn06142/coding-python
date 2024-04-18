#include<iostream>
#include<algorithms>
using namespace std;
int main() {
    int squares = 0, h, v, cnt = 0;
    cin >> n >> m;
    int x[n], y[m], l[(long long) n * (n + 1)/2], r[(long long) m *(m + 1)/2];
    for(int i = 0; i < n - 1; i++) { 
        for(int j = i + 1; i < n; i++) {
            l[++cnt] = abs(x[i] - x[j]);
        }
    }
    for(int i = 0; i <  m - 1; i++) { 
        for(int j = i + 1; i < m; i++) {
            r[++cnt] = abs(y[i] - y[j]);
        }
    }
    sort(r + 1, r + m *(m + 1)/2 + 1);
    for(int i = 0; i < m *(m + 1)/2; i++) {
        tmp = lower_bound()
    }
}