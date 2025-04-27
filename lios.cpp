#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    static const vector<string> symbols = {
        "H","HE","LI","BE","B","C","N","O","F","NE",
        "NA","MG","AL","SI","P","S","CL","AR","K","CA",
        "SC","TI","V","CR","MN","FE","CO","NI","CU","ZN",
        "GA","GE","AS","SE","BR","KR","RB","SR","Y","ZR",
        "NB","MO","TC","RU","RH","PD","AG","CD","IN","SN",
        "SB","TE","I","XE","CS","BA","LA","CE","PR","ND",
        "PM","SM","EU","GD","TB","DY","HO","ER","TM","YB",
        "LU","HF","TA","W","RE","OS","IR","PT","AU","HG",
        "TL","PB","BI","PO","AT","RN","FR","RA","AC","TH",
        "PA","U","NP","PU","AM","CM","BK","CF","ES","FM",
        "MD","NO","LR","RF","DB","SG","BH","HS","MT","DS",
        "RG","CN","NH","FL","MC","LV","TS","OG"
    };

    bool is_one[26] = {false};
    bool is_two[26][26] = {{false}};
    for (auto &sym : symbols) {
        if (sym.size() == 1) {
            is_one[sym[0] - 'A'] = true;
        } else {
            is_two[sym[0] - 'A'][sym[1] - 'A'] = true;
        }
    }

    int n;
    cin >> n;
    string s;
    vector<char> dp;

    while (n--) {
        cin >> s;
        int m = s.size();
        dp.assign(m+1, 0);
        dp[0] = 1;

        bool ok = false;
        for (int i = 1; i <= m; ++i) {
            int c1 = s[i-1] - 'A';

            if (dp[i-1] && is_one[c1]) {
                dp[i] = 1;
            }

            else if (i >= 2 && dp[i-2]) {
                int c0 = s[i-2] - 'A';
                if (is_two[c0][c1]) {
                    dp[i] = 1;
                }
            }

            if (i >= 2 && !dp[i] && !dp[i-1] && !dp[i-2]) {
                ok = false;
                break;
            }

            if (i == m) {
                ok = dp[m];
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}