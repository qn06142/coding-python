#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> prime_count(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prime_count[i + 1] = prime_count[i] + (is_prime(a[i]) ? 1 : 0);
    }
    
    int result = 0;
    int min_left = 0, max_left = 0;
    
    for (int right = 0; right < n; ++right) {
        while (min_left <= right && prime_count[right + 1] - prime_count[min_left] > r) {
            ++min_left;
        }
        while (max_left <= right && prime_count[right + 1] - prime_count[max_left] >= l) {
            ++max_left;
        }
        result += max_left - min_left;
    }
    
    cout << result << endl;
    
    return 0;
}
