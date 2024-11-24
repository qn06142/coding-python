#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
vector<int> primes; 

void sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve(1000000); 

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) cin >> B[i];

    vector<long long> hashA(N + 1, 0), hashB(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        hashA[i] = hashA[i - 1] + primes[A[i]];
        hashB[i] = hashB[i - 1] + primes[B[i]];
    }

    while (Q--) {
        int li, ri, Li, Ri;
        cin >> li >> ri >> Li >> Ri;
        //(hopefully) unordered hashing that is good
        long long hash1 = hashA[ri] - hashA[li - 1];
        long long hash2 = hashB[Ri] - hashB[Li - 1];

        if (hash1 == hash2) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}