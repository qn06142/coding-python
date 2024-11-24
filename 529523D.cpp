#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int N = 1005;
int n, m, L[N], h[N];
long long F[N], ans;
char a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin.ignore();  // To ignore the newline after the last integer input

    for (int i = 1; i <= n; ++i) {
        cin.getline(a + 1, m + 1);
        
        for (int j = 1; j <= m; ++j) {
            h[j] = (a[j] == '1') ? h[j] + 1 : 0;
        }

        stack<int> st;
        for (int j = 1; j <= m; ++j) {
            while (!st.empty() && h[j] <= h[st.top()]) {
                st.pop();
            }
            L[j] = st.empty() ? 1 : st.top() + 1;
            st.push(j);
        }

        for (int j = 1; j <= m; ++j) {
            int k = L[j] - 1;
            F[j] = (long long)h[j] * (j - k) + F[k];
            ans += F[j];
        }
    }

    cout << ans << '\n';

    return 0;
}
