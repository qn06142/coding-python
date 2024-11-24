#include<iostream>

using namespace std;
int a[(int) 1e5 + 5], pref[(int) 1e5 + 5];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
    int count = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            count += (((pref[j] - pref[i - 1]) / (j - i + 1)) >= k);
            cout << i << " " << j << " " << (pref[j] - pref[i - 1]) << " " << ((pref[j] - pref[i - 1]) / (j - i + 1)) << endl;
        }
    }
    cout << count;
}