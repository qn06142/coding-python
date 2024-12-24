#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const long long MOD = 846103811092001LL;

long long mod_mul(long long a, long long b, long long mod) {
    return (a % mod * b % mod) % mod;
}

long long mod_add(long long a, long long b, long long mod) {
    return (a % mod + b % mod) % mod;
}

long long sum(long long x) {
    return mod_mul(mod_mul(x, x + 1, MOD), 423051905546001LL, MOD); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> left(n + 1), right(n + 1);
    stack<int> st;

    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        left[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n; i >= 1; --i) {
        while (!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        int l = left[i];
        int r = right[i];

        long long contrib1 = mod_mul(sum(i - l), r - i, MOD); 
        long long contrib2 = mod_mul(sum(r - i - 1), i - l, MOD); 
        long long contrib = mod_mul(mod_add(contrib1, contrib2, MOD), a[i], MOD);

        result = mod_add(result, contrib, MOD);
    }

    cout << result << "\n";
    return 0;
}