#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;  
int a[MAX_N + 1];  
int left_bound[MAX_N + 1];  
int right_bound[MAX_N + 1];  

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    stack<int> s, s1;

    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }
        left_bound[i] = s.empty() ? 1 : s.top();
        s.push(i);
    }

    for (int i = n; i >= 1; i--) {
        while (!s1.empty() && a[s1.top()] <= a[i]) {
            s1.pop();
        }
        right_bound[i] = s1.empty() ? n : s1.top();
        s1.push(i);
    }

    long long cnt = 0;

    for (int i = 1; i <= n; i++) {
        int l = left_bound[i];
        int r = right_bound[i];

        cnt += r - l - 1;
    }

    cout << cnt << endl;
    return 0;
}