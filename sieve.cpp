#include <iostream>
#include <vector>

void SieveOfEratosthenes(int n) {
    std::vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p*p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p*p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            std::cout << p << " ";
}

int main() {
    int n;
    std::cin >> n;
    SieveOfEratosthenes(n);
    return 0;
}
