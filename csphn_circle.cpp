#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    long long S = 0;

    // Đọc dãy B và tính tổng S
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        S += b[i];
    }

    // Kiểm tra nếu S không chia hết cho 3
    if (S % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    long long sumA = S / 3;
    int a1 = (b[0] + b[n - 1] - b[1]) / 2;

    vector<int> a(n);
    a[0] = a1;

    // Tính các phần tử tiếp theo của dãy A
    for (int i = 1; i < n; ++i) {
        a[i] = b[i - 1] - a[i - 1] - (i == 1 ? a[n - 1] : a[i - 2]);
    }


    // In dãy A
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
