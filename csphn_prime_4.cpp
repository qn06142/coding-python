#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MAX_NUM = 1e7;  
#define int long long
bool isPrime[MAX_NUM + 1];

void sieve() {
    fill(isPrime, isPrime + MAX_NUM + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX_NUM; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_NUM; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

signed main() {
    string T;
    cin >> T;

    sieve();

    set<int> primes;   
    vector<int> result; 
    int n = T.length();

    for (int i = 0; i < n; ++i) {

        if (isdigit(T[i])) {

            int num = 0;
            for (int j = i; j < n && isdigit(T[j]); ++j) {
                num = num * 10 + (T[j] - '0'); 

                if (isPrime[num] && primes.find(num) == primes.end()) {
                    primes.insert(num);
                    result.push_back(num);
                }
            }
        }
    }

    cout << result.size() << endl;

    for (int prime : result) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}