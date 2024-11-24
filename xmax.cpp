#include<bits/stdc++.h>

using namespace std;
//map<char, int> pos;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string srevers = s;
    reverse(srevers.begin(), srevers.end());
    srevers = ' ' + srevers;
    s = ' ' + s;
    int i = 1, j = 1, ans = 0;
    while (i <= n) {
        
        j = i;
        while(s[j] != srevers[i]) j++;
        while(i < j) {
            char tmp;
            tmp = s[j];
            s[j] = s[j - 1];
            s[j - 1] = tmp;
            j --;
            ans ++;
        }
        i++;
    }
    cout << ans << "\n";
}