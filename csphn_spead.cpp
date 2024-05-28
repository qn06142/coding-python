#include<iostream>

using namespace std;
int pref[(int) 1e6];
int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int i, k;
        cin >> i >> k;
        pref[n + 1] -= k / n;
        pref[1] += k / n;
        pref[i] += 1;
        pref[i + (k % n)] -= 1;
    }
    for(int i = 1; i <= n * 2; i++) {
        pref[i] += pref[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        cout << pref[i] + pref[i + n] << ' ';
    }
}