#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long m, a, b, c;
        cin >> m >> a >> b >> c;

        long long fila1 = min(a, m);
        long long filb2 = min(b, m);

        long long rem1 = m - fila1;
        long long rem2 = m - filb2;

        long long c1 = min(c, rem1);
        long long c2 = min(c - c1, rem2);

        long long ans = fila1 + filb2 + c1 + c2;

        cout << ans << '\n';
    }

    return 0;
}
