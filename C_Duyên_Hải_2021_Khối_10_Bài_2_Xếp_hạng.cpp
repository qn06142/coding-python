#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> sum(n);
    for (int i = 0; i < n; i++) {
        sum[i] = a[i] + b[i];
    }
    vector<int> best(n), worst(n);
    for (int i = 0; i < n; i++) {
        best[i] = i + 1;
        worst[i] = n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sum[j] < sum[i]) {
                best[i]--;
            }
            if (sum[j] > sum[i]) {
                worst[i]--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << best[i] << " " << worst[i] << endl;
    }
    return 0;
}