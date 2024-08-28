#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Tạo dãy Fibonacci cho đến khi vượt quá 5 * 10^18
vector<long long> generate_fibo_up_to_limit(long long limit) {
    vector<long long> fibo = {1, 1};
    while (true) {
        long long next_fib = fibo.back() + fibo[fibo.size() - 2];
        if (next_fib > limit) break;
        fibo.push_back(next_fib);
    }
    return fibo;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long limit = 5e18;
    vector<long long> fibo = generate_fibo_up_to_limit(limit);

    int t;
    cin >> t;

    while (t--) {
        long long l, r;
        cin >> l >> r;

        // Tìm vị trí đầu tiên lớn hơn hoặc bằng l
        auto lower = lower_bound(fibo.begin(), fibo.end(), l);
        // Tìm vị trí đầu tiên lớn hơn r
        auto upper = upper_bound(fibo.begin(), fibo.end(), r);

        // Số lượng các số Fibonacci trong khoảng [l, r]
        cout << upper - lower << "\n";
    }

    return 0;
}
