#include <iostream>
#include <string>
using namespace std;
const int mod = 1e9 + 7;
int main() {
    string s;
    long long K;
    cin >> s >> K;

    string stacked_string = "";
    for (long long i = 0; i < K; i++) {
        stacked_string += s;
    }

    long long count = 0;
    long long cnt1 = 0;
    for (size_t i = 0; i < stacked_string.size(); i++) {
        if(stacked_string[i] == 'H') {
            cnt1 ++;
        } else {
            count += cnt1;
        }
        count %= mod;
        cnt1 %= mod;
    }

    cout << count << endl;
    return 0;
}