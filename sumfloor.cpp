#include <bits/stdc++.h>
using namespace std;

#define int long long

int sumUpTo(int x) {
    return x * (x + 1) / 2;
}

int calc(int x) {
    if (x <= 0) return 0; 

    int sum = 0;
    int k = 1; 

    while (k * k <= x) {
        int next = min((k + 1) * (k + 1) - 1, x); 
        sum += k * (next - k * k + 1);            
        k++;
    }
    return sum;
}

signed main() {
    int a, b;
    cin >> a >> b;

    int result = calc(b) - calc(a - 1);
    cout << result << endl;

    return 0;
}