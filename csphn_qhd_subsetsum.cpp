#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> A(n + 1);  
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
    }
    if(m > sum) {
        cout << "NO\n";
        return 0;
    }
    vector<bool> dp(m + 1, false);
    vector<int> trace(m + 1, -1);  
    dp[0] = true;  

    for (int i = 1; i <= n; i++) {

        for (int j = m; j >= A[i]; j--) {
            if (dp[j - A[i]]) {  
                if (!dp[j]) {    
                    dp[j] = true;
                    trace[j] = i;  
                }
            }
        }
    }

    if (!dp[m]) {
        cout << "NO\n";  
    } else {
        cout << "YES\n";  
        vector<int> result;
        int total = m;
        while (total > 0) {
            result.push_back(trace[total]);  
            total -= A[trace[total]];        
        }
        cout << result.size() << '\n';  
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";   
        }
        cout << '\n';
    }

    return 0;
}