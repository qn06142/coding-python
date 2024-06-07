#include<bits/stdc++.h>
using namespace std;
string ans = "999999999999999999", s;
int fail = 0;
void check(string s1) {
    int st = s1[0] - '0';
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '+') st++;
        else if (s[i] == '-') {
            st--;
        }
        if(st == -1 or st == 10) {
            return;
        }
        s1 += char(st + 48);
    }
    if(s1 < ans) ans = s1, fail = 1;
}
string st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(int i = 1; i < 9; i++) {
        st = char(i + 48);
        check(st);
    }
    return 1;
    cout << (fail ? ans : 0);
}
