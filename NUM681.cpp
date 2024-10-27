#include <iostream>
using namespace std;

bool contains6or8(int x) {
    while (x > 0) {
        int digit = x % 10;
        if (digit == 6 || digit == 8) return true;
        x /= 10;
    }
    return false;
}

int main() {
    long long N;
    while (cin >> N) {
        int count = 0;

        for (int A = 1; A <= N / 2; ++A) {
            int B = N - A;

            if (contains6or8(A) || contains6or8(B)) {
                cerr << A << ' ' << B << '\n';
                ++count;
            }
        }

        cout << count << '\n';
    }
    return 0;
}