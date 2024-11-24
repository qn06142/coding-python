#include <iostream>
using namespace std;

int count_divisors(int n) {
    int divisors = 0;
    int i = 1;
    while (i * i <= n) {
        if (n % i == 0) {
            if (i * i == n) {
                divisors += 1;
            } else {
                divisors += 2;
            }
        }
        i += 1;
    }
    return divisors;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int num;
        cin >> num;
        cout << count_divisors(num) << endl;
    }
    return 0;
}
