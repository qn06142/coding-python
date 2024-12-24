#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 +  3;
int spf[MAXN];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++) 
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2) 
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int minimumRemovals(int a[], int n) {
    int g = 0;

    for (int i = 0; i < n; i++) 
        g = __gcd(a[i], g);

    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++) 
        a[i] = a[i] / g;

    for (int i = 0; i < n; i++) {
        vector<int> p = getFactorization(a[i]);
        set<int> s;

        for (int j = 0; j < p.size(); j++) 
            s.insert(p[j]);

        for (auto it = s.begin(); it != s.end(); it++) {
            int el = *it;
            mpp[el] += 1;
        }
    }

    int mini = INT_MAX;

    for (auto it = mpp.begin(); it != mpp.end(); it++) {
        int fir = it->first;
        int sec = it->second;

        if ((n - sec) <= mini) {
            mini = n - sec;
        }
    }

    return (mini != INT_MAX) ? mini : -1;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) 
        cin >> a[i];

    sieve();
    cout << minimumRemovals(a, n) << endl;

    return 0;
}
