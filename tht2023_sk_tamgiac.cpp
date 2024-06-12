#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ns(n + 5);

    for (int i = 1; i <= n; ++i) {
        cin >> ns[i];
    }
    int A = n * (n - 1) * (n - 2) / 6;
    vector<int> primes;
    vector<bool> primesmark(1e7);
    for(int i = 2; i <= 1e7; i++) {
        for(int j = i; j <= 1e7; j += i) {
            primesmark[i] = false;
        }
    }
    for(int i = 2; i <= 1e7; i++) {
        if(primesmark[i]) {
            primes.push_back(i);
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++) {
        
    }
    return 0;
}