#include<iostream>
#include<string.h>
using namespace std;
const int maxn = (int) 3e3 + 5;
int dp[maxn][maxn];
string s1, s2;
int main() {
    cin >> s1 >> s2;
    int n1, n2;
    n1 = s1.length();
    n2 = s2.length();
    memset(dp, 0, sizeof(dp)); // Initialize the entire dp array to 0
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    int ind = dp[n1][n2];
    string lcs(ind, ' '); // Initialize the LCS string with the correct length
    int i = n1, j = n2;
    while(i > 0 and j > 0) {
        if(s1[i - 1] == s2[j - 1]) {
            lcs[ind - 1] = s1[i - 1]; // Add the character to the LCS string
            i--;
            j--;
            ind--;
        } else if(dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << lcs;
    return 0;
}
