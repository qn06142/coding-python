#include <iostream>

using namespace std;

int main() {
    unsigned long long N;
    cin >> N;

    unsigned long long count5 = 0;

    for (unsigned long long i = 5; N / i >= 1; i *= 5) {
        count5 += N / i;
    }

    cout << count5 << endl;
    return 0;
}