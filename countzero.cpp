#include<iostream>
using namespace std;
int main() {
    long long n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    long long count = 0;
    for (long long i = 5; n / i >= 1; i *= 5)
        count += n / i;
    cout << count;
}