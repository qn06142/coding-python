#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;
const int maxn = 3e5 + 5;
long long a[maxn], pref[maxn], dp[maxn], trace[maxn];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    for(int i = 0; i < maxn; i++) dp[i] = 1e9;
    //dp[i] represents arr from ind 1 to i
    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        vector<int> js;
        for(int j = i; j <= n; j++) {
            if(pref[j] - pref[i - 1] > 0) {
                if(max(dp[i - 1], (long long) j - i + 1) < dp[j]) {
                    trace[j] = i;
                    dp[j] = max(dp[i - 1], (long long) j - i + 1);
                }
            }
        }
    }
    vector<int> tmp;
    int i = n;
    while(trace[i] != 0 and i > 0) {
        tmp.push_back(i - trace[i] + 1);
        i = trace[i] - 1;
    }
    cout << tmp.size() << " " << dp[n];
    cout << endl;
    for(int i = tmp.size() - 1; i >= 0; i--) {
        cout << tmp[i] << " ";
    }
}