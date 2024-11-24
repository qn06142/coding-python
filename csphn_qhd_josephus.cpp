#include <iostream>
using namespace std;

int josephus(int n, int m) {
    int result = 0;
    for (int i = 2; i <= n; i++) {
        result = (result + m) % i;
    }
    return result;
}

int main() {
    int n, m, p, y;
    cin >> n >> m;
    cin >> p >> y;

    int q = (josephus(n, m) + p) % n;

    int x = (y - josephus(n, m) + n) % n;

    cout << q << " " << x << endl;
    return 0;
}