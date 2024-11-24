#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> readVector(int n) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) cin >> res[i];
    return res;
}

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v = readVector(n);

    map<int, long long> results;
    map<int, int> divisors;

    for (int i = 0; i < n; i++) {
        map<int, int> nextDivisors;
        for (const auto &p : divisors) {
            nextDivisors[gcd(p.first, v[i])] += p.second;
        }
        nextDivisors[v[i]]++;

        for (const auto &p : nextDivisors)
            results[p.first] += p.second;

        divisors = move(nextDivisors);
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << results[x] << endl;
    }
}
