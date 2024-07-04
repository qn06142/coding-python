#include<bits/stdc++.h>

using namespace std;

int a[(int) 1e5 + 5], bit[(int) 1e5 + 5];
void bit(int u, int v, int n) {
    while(u <= n) {
        bit[u] = max(bit[u], v);
        u += u & -u;
    }
}

int main() {
    
}