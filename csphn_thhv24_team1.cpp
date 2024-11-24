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

    // Calculate left bounds
    for (int i = 1; i <= n; i++) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }
        left_bound[i] = s.empty() ? 0 : s.top();
        s.push(i);
    }

    // Calculate right bounds
    for (int i = n; i >= 1; i--) {
        while (!s1.empty() && a[s1.top()] <= a[i]) {
            s1.pop();
        }
        right_bound[i] = s1.empty() ? n + 1 : s1.top();
        s1.push(i);
    }

    long long perfect_subarrays_count = 0;

    // Counting valid subarrays
    for (int i = 1; i <= n; i++) {
        int l = left_bound[i];
        int r = right_bound[i];
        // The number of valid subarrays ending at `i`
        perfect_subarrays_count += (i - l - 1) + (r - i - 1);
    }

    cout << perfect_subarrays_count << endl;
    return 0;
}
