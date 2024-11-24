#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
 
int main() {
	freopen("huunghi.inp", "r", stdin);
	freopen("huunghi.out", "w", stdout);
	int bruh;
	cin >> bruh;
    for (int i = 1; i <= bruh; i++) {
        vector<int> divisors;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                divisors.push_back(j);
            }
        int sum_divisors = 0;
        for (int divisor : divisors) {
            sum_divisors += divisor;
        }
        if (sum_divisors == j && accumulate(begin(divisors), end(divisors), 0,
            [](int acc, int divisor) { return acc + ((divisor == 1) ? 0 : divisor); }) == i) {
            cout << i << " " << j << "\n";
        }
        }
    }
    return 0;
}
