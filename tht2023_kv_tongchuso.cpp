#include <iostream>
#include <string>

using namespace std;

int a, b, n, m, d, k, x, v, test;
string s, s1, s2;	
bool kt;

void solve() {
    k = 0;
    for (int i = 0; i <= s.size() - 1; i++) 
        k += s[i] - '0';
    
    d = 0;
    s1 = "";
    s2 = "";

    if (s.size() == 1 && (s[0] - '0') % 2) {  // special case: single-digit odd numbers
        cout << -1;
        return;
    }

    if (k % 2) {  // If the sum of digits is odd
        v = 0;
        for (int i = 0; i <= s.size() - 2; i++) {  // find the position to subtract 1
            if (s[i + 1] != '9') {
                v = i;
                break;
            }
        }

        if (s[v + 1] == '9') {  // If all characters from the second onwards are 9
            cout << -1;
            return;
        }

        s[v] = s[v] - '0' - 1 + '0';
    }

    for (int i = 0; i <= s.size() - 1; i++) {
        m = s[i] - '0', a = m - (m / 2), b = m / 2;

        if ((s[i] - '0') % 2) d++;

        // if d is odd, add larger number to s1 and smaller to s2
        // if d is even, do the opposite
        if (d % 2) {
            s1 += (char)(a + '0');
            s2 += (char)(b + '0');
        } else {
            s1 += (char)(b + '0');
            s2 += (char)(a + '0');
        }
    }

    if (k % 2) {
        s1[v + 1] = s1[v + 1] - '0' + 5 + '0';
        s2[v + 1] = s2[v + 1] - '0' + 5 + '0';
    }

    int i = 0;
    while (s1[i] == '0') i++;
    for (; i <= s1.size() - 1; i++) cout << s1[i];

    cout << " ";

    i = 0;
    while (s2[i] == '0') i++;
    for (; i <= s2.size() - 1; i++) cout << s2[i];
}

void inp() {
    cin >> test;

    while (test--) {
        cin >> s;
        solve();
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    inp();

    return 0;
}
