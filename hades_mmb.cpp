#include <bits/stdc++.h>
using namespace std;

#define staccempty() while(!stacc.empty())stacc.pop();
#define testsig cerr << "yes" << endl;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    vector<int> l1(n + 1), l2(n + 1), r1(n + 1), r2(n + 1);
    stack<int> stacc;

    // Compute l1
    for(int i = 1; i <= n; i++) {
        while(!stacc.empty() && a[stacc.top()] >= a[i]) stacc.pop();
        l1[i] = stacc.empty() ? 1 : stacc.top() + 1;
        stacc.push(i);
    }
    staccempty()

    // Compute r1
    for(int i = n; i >= 1; i--) {
        while(!stacc.empty() && a[stacc.top()] >= a[i]) stacc.pop();
        r1[i] = stacc.empty() ? n : stacc.top() - 1;
        stacc.push(i);
    }
    staccempty()

    // Compute l2
    for(int i = 1; i <= n; i++) {
        while(!stacc.empty() && b[stacc.top()] >= b[i]) stacc.pop();
        l2[i] = stacc.empty() ? 1 : stacc.top() + 1;
        stacc.push(i);
    }
    staccempty()

    // Compute r2
    for(int i = n; i >= 1; i--) {
        while(!stacc.empty() && b[stacc.top()] >= b[i]) stacc.pop();
        r2[i] = stacc.empty() ? n : stacc.top() - 1;
        stacc.push(i);
    }
    staccempty()

    long long count = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = l2[i]; j <= r2[i]; j++) {
            if (l1[j] <= i && i <= r1[j]) {
                count++;
            }
        }
    }

    cout << count * 2 % 1234567891;

    return 0;
}
