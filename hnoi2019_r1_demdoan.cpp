#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);

    long long N;
    cin >> N;

    long long count = 0;
    long long doubleN = 2 * N; 

    for (long long d = 1; d * d <= doubleN; ++d) {
        if (doubleN % d == 0) {

            long long sumAB = d;
            long long length = doubleN / d;

            if ((sumAB + length - 1) % 2 == 0 && (length - sumAB + 1) % 2 == 0) {
                long long a = (length - sumAB + 1) / 2;
                long long b = (sumAB + length - 1) / 2;
                if (a > 0 && a <= b) {
                    count++;
                }
            }

            if (d != doubleN / d) { 
                sumAB = doubleN / d;
                length = d;

                if ((sumAB + length - 1) % 2 == 0 && (length - sumAB + 1) % 2 == 0) {
                    long long a = (length - sumAB + 1) / 2;
                    long long b = (sumAB + length - 1) / 2;
                    if (a > 0 && a <= b) {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}