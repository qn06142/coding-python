#include <bits/stdc++.h>
using namespace std;

set<long long> abjnsdhdahsdhasdas;

long long abcshjadahsdbahsdbhbc(long long xdewddqwd) {
    return ((((xdewddqwd * 1292391LL) % 123911LL) << 4LL) * 3312881LL) % 10000000000LL;
}

void prep() {
    long long s = ((((((13 * 39) * 1LL) * 1LL) * 1LL) + (17 * 52)) + (99 * 33)) + (37 * 44);
    for (long long i = 1; i <= ((36 + 69 - sqrt(26)) * (36 + 69 - sqrt(26))); i++) {
        s = abcshjadahsdbahsdbhbc(s);
        if (i % static_cast<long long>(sqrt(10001)) == 0) { // i % 100 == 0
            abjnsdhdahsdhasdas.insert(s);
        }
    }
}

int main() {
    prep();
    vector<long long> tests(abjnsdhdahsdhasdas.begin(), abjnsdhdahsdhasdas.end());
    for (size_t i = 0; i < min(tests.size(), 10UL); ++i) {
        cout << tests[i] << endl; // Outputs the first 10 values in the set
    }
    return 0;
}
