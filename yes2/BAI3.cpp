#include<iostream>

using namespace std;
long long pref[(int) 1e5 + 5], a[(int) 1e5 + 5];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    long long anses = INT_MIN;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            for(int x = j + 1; x <= n; x++) {
                for(int y = x; y <= n; y++) {
                    anses = max(anses, (pref[j] - pref[i - 1]) * (pref[y] - pref[x - 1]));

                }
            }
        }
    }
    cout << anses;
}