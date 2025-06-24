#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long M, N;
    cin >> N >> M;

    // lãi suất theo tháng (1-based), chuyển sang dạng thập phân
    vector<double> annual_rate = {
        0.0,     // dummy để 1-based
        3.90/100, 3.92/100, 3.95/100, 3.99/100,
        4.04/100, 5.54/100, 5.72/100, 5.92/100,
        6.14/100, 6.38/100, 6.64/100, 6.92/100
    };

    // g[k] = hệ số nhân tối ưu cho k tháng
    vector<double> g(M + 1, 0.0);
    g[0] = 1.0;

    for (int k = 1; k <= M; ++k) {
        double best = 0.0;
        for (int t = 1; t <= 12 && t <= k; ++t) {
            // nếu gửi t tháng, sau t tháng ta được nhân 1 + r_t * (t/12)
            double factor = 1.0 + annual_rate[t] * (t / 12.0);
            best = max(best, g[k - t] * factor);
        }
        g[k] = best;
    }

    // tính tổng hệ số S = sum_{k=1..M} g[k]
    double S = 0.0;
    for (int k = 1; k <= M; ++k) {
        S += g[k];
    }
    cout << fixed << setprecision(4) << (double) N / S << "\n";

    return 0;
}
