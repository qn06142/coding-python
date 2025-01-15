#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int> compute_prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;

    vector<int> prefix = compute_prefix_function(s);
    for (int x : prefix) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
