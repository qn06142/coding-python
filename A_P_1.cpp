#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int count0a = count(a.begin(), a.end(), 0);
    int count1a = count(a.begin(), a.end(), 1);
    int count0b = count(b.begin(), b.end(), 0);
    int count1b = count(b.begin(), b.end(), 1);

    int total0 = count0a + count0b;
    int total1 = count1a + count1b;

    vector<int> even(total0), odd(total1);
    for (int i = 0; i < total0; i++) {
        even[i] = 2 * (i + 1);
    }
    for (int i = 0; i < total1; i++) {
        odd[i] = 2 * (i + 1) - 1;
    }

    int result = 0;
    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            result = max(result, even[evenIndex++]);
        } else {
            result = max(result, odd[oddIndex++]);
        }
    }
    for (int i = 0; i < m; i++) {
        if (b[i] == 0) {
            result = max(result, even[evenIndex++]);
        } else {
            result = max(result, odd[oddIndex++]);
        }
    }

    cout << result << endl;

    return 0;
}