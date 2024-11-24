#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> fractions;
    k--;

    int a = 0, b = 1, c = 1, d = n;
    fractions.push_back({a, b}); 

    while (c <= n) {

        int p = (n + b) / d;
        int newA = p * c - a;
        int newB = p * d - b;
        fractions.push_back({c, d});

        a = c;
        b = d;
        c = newA;
        d = newB;
    }

    cout << fractions[k].first << " " << fractions[k].second << endl;

    return 0;
}