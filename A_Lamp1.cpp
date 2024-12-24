#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
int n;
string b;
int min_operations = INT_MAX;


void backtrack(string a, int operations, int start) {

    if (operations >= min_operations) return;


    if (a == b) {
        min_operations = min(min_operations, operations);
        return;
    }


    for (int l = start; l < n; ++l) {
        for (int r = l; r < n; ++r) {

            string original = a;


            for (int i = l; i <= r; ++i) a[i] = '1';
            backtrack(a, operations + 1, r + 1);
            a = original;


            for (int i = l; i <= r; ++i) a[i] = '0';
            backtrack(a, operations + 1, r + 1);
            a = original;


            for (int i = l; i <= r; ++i) a[i] = (a[i] == '0' ? '1' : '0');
            backtrack(a, operations + 1, r + 1);
            a = original;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    cin >> n;
    string a;
    cin >> a >> b;


    backtrack(a, 0, 0);


    cout << min_operations << "\n";

    return 0;
}
