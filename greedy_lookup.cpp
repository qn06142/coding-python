#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;
    long long L = s.size();

    vector<long long> a(n+1), lens(n+1);
    // Đọc a[1..n]
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Tính prefix sums của độ dài sau mỗi bước
    lens[0] = L;
    for (int i = 1; i <= n; i++) {
        lens[i] = lens[i-1] + a[i];
    }

    // Xử lý m truy vấn
    while (m--) {
        long long k;
        cin >> k;
        if (k > lens[n]) {
            cout << -1 << "\n";
            continue;
        }

        // Lùi dần về trạng thái gốc
        int idx = n;
        while (idx > 0) {
            // Nếu k nằm trong phần độ dài trước khi bước idx
            if (k <= lens[idx-1]) {
                idx--;
            } else {
                // k nằm trong phần thêm của bước idx
                long long offset = k - lens[idx-1];           // vị trí trong phần thêm
                long long mirrored_pos = a[idx] - offset + 1;  // vị trí tương ứng trước đó
                k = mirrored_pos;
                idx--;
            }
        }

        // Sau cùng idx == 0, k nằm trong xâu gốc
        cout << s[k-1] << "\n";
    }

    return 0;
}
