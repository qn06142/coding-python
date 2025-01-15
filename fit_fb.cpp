#include <iostream>
using namespace std;

int main() {
<<<<<<< Updated upstream
    long long x;
    cin >> x;
    cout << x - 1 << " " << (x  + 1) / 2 << endl;

    return 0;
=======
    #define int long long
    int n, n_;
    cin >> n_;
    n = n_;
    int ans = 0;

    while (n > 1) {
        if (n % 2 == 0) {
            ans += n / 2;
            n = n / 2;
        } else {
            ans += (n - 1) / 2;
            n = (n - 1) / 2;
        }
    }
    cout << n_ - 1 << ' ' << ans << '\n';
>>>>>>> Stashed changes
}
