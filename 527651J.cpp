#include <iostream>
#include <vector>

using namespace std;

const long long MAX_N = 1e14;

void preprocess(vector<long long>& largestDivisor, long long max_n) {
    for (long long i = 2; i <= max_n; ++i) {
        if (largestDivisor[i] == 0) { 
            for (long long j = i; j <= max_n; j += i) {
                if (largestDivisor[j] == 0) {
                    largestDivisor[j] = j / i;
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    vector<long long> n(T);
    long long max_n = 0;

    for (int i = 0; i < T; ++i) {
        cin >> n[i];
        if (n[i] > max_n) max_n = n[i];
    }

    vector<long long> largestDivisor(max_n + 1, 0);

    preprocess(largestDivisor, max_n);

    for (int i = 0; i < T; ++i) {
        if (n[i] == 1) {
            cout << -1 << endl;
        } else {
            cout << (largestDivisor[n[i]] == 1 ? -1 :largestDivisor[n[i]]) << endl;
        }
    }

    return 0;
}