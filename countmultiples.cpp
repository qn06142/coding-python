#include<iostream>
using namespace std;

long long sum_divisible_by_k(int l, int r, int k) {
    long long sum = 0;
    for (int i = max(l, k); i <= max(r, k); i++) {
        if (i % k == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int l, r, k;
    cin >> l >> r >> k;
    cout << sum_divisible_by_k(l, r, k);
    return 0;
}
