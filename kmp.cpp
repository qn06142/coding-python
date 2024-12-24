#include<bits/stdc++.h>
using namespace std;

string s;
int n;

vector<int> prefix_function(string s) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.size();

    vector<int> lps = prefix_function(s);
    for (int i = 0; i < n; i++) {
        cout << lps[i] << " ";
    }
    cout << endl;

    return 0;
}
