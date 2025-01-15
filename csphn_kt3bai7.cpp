#include <iostream>
#include <string>
using namespace std;

bool check(int a, int b, int c, int d, const string& s) {
    int n = s.size();

    if (n != a + b + 2 * c + 2 * d) return false;

    int count0 = 0, count1 = 0;
    for (char ch : s) {
        if (ch == '0') count0++;
        else count1++;
    }
    if (count0 != a + c + d || count1 != b + c + d) return false;

    int used_c = 0, used_d = 0; 
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '1') {
            if (used_c < c) used_c++; 
            else return false;       
            i++; 
        } else if (s[i] == '1' && s[i + 1] == '0') {
            if (used_d < d) used_d++; 
            else return false;       
            i++; 
        }
    }

    return used_c == c && used_d == d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        string s;
        cin >> a >> b >> c >> d >> s;
        if (check(a, b, c, d, s)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}