#include <iostream>
#include <stack>
using namespace std;

int a[(int) 1e6 + 5], lmi[(int) 1e6 + 5], rmi[(int) 1e6 + 5], lmx[(int) 1e6 + 5], rmx[(int) 1e6 + 5];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    stack<int> stacc;

    // Calculate left boundaries for maximums
    for(int i = 1; i <= n; i++) {
        while(!stacc.empty() && a[stacc.top()] <= a[i]) stacc.pop();
        lmx[i] = (stacc.empty() ? 1 : stacc.top() + 1);
        stacc.push(i);
    }

    // Clear stack for reuse
    while(!stacc.empty()) stacc.pop();

    // Calculate right boundaries for maximums
    for(int i = n; i >= 1; i--) {
        while(!stacc.empty() && a[stacc.top()] < a[i]) stacc.pop();
        rmx[i] = (stacc.empty() ? n : stacc.top() - 1);
        stacc.push(i);
    }

    // Clear stack for reuse
    while(!stacc.empty()) stacc.pop();

    // Calculate left boundaries for minimums
    for(int i = 1; i <= n; i++) {
        while(!stacc.empty() && a[stacc.top()] >= a[i]) stacc.pop();
        lmi[i] = (stacc.empty() ? 1 : stacc.top() + 1);
        stacc.push(i);
    }

    // Clear stack for reuse
    while(!stacc.empty()) stacc.pop();

    // Calculate right boundaries for minimums
    for(int i = n; i >= 1; i--) {
        while(!stacc.empty() && a[stacc.top()] > a[i]) stacc.pop();
        rmi[i] = (stacc.empty() ? n : stacc.top() - 1);
        stacc.push(i);
    }

    // Calculate the final answer
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        // Contribution as maximum
        ans += (long long)(i - lmx[i] + 1) * (rmx[i] - i + 1) * a[i];
        // Contribution as minimum (subtracting)
        ans -= (long long)(i - lmi[i] + 1) * (rmi[i] - i + 1) * a[i];
    }

    cout << ans << endl;
    return 0;
}
