#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 1e7; 
bool is_divisor[MAX_SIZE + 1] = {false};
int main() {
    long long L, R;
    cin >> L >> R;


    for (long long i = 1; i <= MAX_SIZE; i++) {

        for (long long j = max(i, (L + i - 1) / i * i); j <= R; j += i) {
            is_divisor[i] = true; 
        }
    }

    long long sum = 0;
    for (int i = 1; i <= MAX_SIZE; i++) {
        if (is_divisor[i]) {
            sum += i;
        }
    }

    cout << sum << endl;
    return 0;
}