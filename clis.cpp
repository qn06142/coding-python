#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int p = 0, q = 0, max_len = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < i + n - 1 && a[j] <= a[j + 1]) {
            j++;
        }
        if (j - i + 1 > max_len) {
            max_len = j - i + 1;
            p = i;
            q = j;
        }
        i = j;
    }

    cout << p + 1 << " " << (q) % n + 1  << endl;

    return 0;
}
