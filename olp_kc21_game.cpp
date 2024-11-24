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

    stack<int> s;

    // Compute left bounds where each a[i] is the minimum
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        left_bound[i] = s.empty() ? 1 : s.top() + 1;
        s.push(i);
    }

    while (!s.empty()) s.pop();  // Clear stack

    // Compute right bounds where each a[i] is the minimum
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] > a[i]) {
            s.pop();
        }
        right_bound[i] = s.empty() ? n : s.top() - 1;
        s.push(i);
    }

    long long cnt = 0;

    // Calculate the total candies needed
    for (int i = 1; i <= n; i++) {
        int l = left_bound[i];
        int r = right_bound[i];
        cnt += (long long)(i - l) * (r - i + 1) * a[i];
    }

    cout << cnt << endl;
    return 0;
}
