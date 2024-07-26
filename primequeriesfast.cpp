#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> simpleSieve(int limit) {
    vector<bool> mark(limit + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= limit; ++p) {
        if (mark[p]) {
            for (int i = p * p; i <= limit; i += p)
                mark[i] = false;
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (mark[p])
            primes.push_back(p);
    }

    return primes;
}

int countPrimesInRange(int low, int high, const vector<int>& primes) {
    if (low == 1) low++; 

    int n = high - low + 1;
    vector<bool> mark(n, true);

    for (int prime : primes) {
        int start = max(prime * prime, (low + prime - 1) / prime * prime);
        for (int j = start; j <= high; j += prime) {
            mark[j - low] = false;
        }
    }

    int primeCount = 0;
    for (int i = 0; i < n; ++i) {
        if (mark[i])
            primeCount++;
    }

    return primeCount;
}

int main() {
    int T;
    cin >> T;

    vector<pair<int, int>> queries(T);
    int maxR = 0;

    for (int i = 0; i < T; ++i) {
        cin >> queries[i].first >> queries[i].second;
        if (queries[i].second > maxR)
            maxR = queries[i].second;
    }

    int limit = sqrt(maxR);
    vector<int> primes = simpleSieve(limit);

    for (const auto& query : queries) {
        int L = query.first;
        int R = query.second;
        cout << countPrimesInRange(L, R, primes) << endl;
    }

    return 0;
}