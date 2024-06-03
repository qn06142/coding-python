#include <iostream>
#include <cmath>
bool issquare(int x) {return floor(sqrt(x)) * floor(sqrt(x)) == x;}
int countSquareDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal, count only one
            if (n / i == i)
                count += (issquare(i));
            else // Otherwise count both
                count += issquare(n / i) + issquare(i);
        }
    }
    return count;
}

int sumSquareDivisors(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += countSquareDivisors(i);
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << sumSquareDivisors(n);
    return 0;
}
