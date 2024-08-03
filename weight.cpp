#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int a[(int) 4e5 + 5], l[(int) 4e5 + 5], r[(int) 4e5 + 5];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    stack<int> s;
    long long total_max = 0, total_min = 0;
    for(int i = 1; i <= n; i++) {
        while(!s.empty() and a[s.top()] <= a[i]) s.pop();
        l[i] = s.empty() ? 1 : s.top() + 1;
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i = n; i >= 1; i--) {
        while(!s.empty() and a[s.top()] < a[i]) s.pop();
        r[i] = s.empty() ? n : s.top() - 1;
        s.push(i);
    }
    for(int i = 1; i <= n; i++) {
        total_max += (long long)(i - l[i] + 1) * (r[i] - i + 1) * a[i];
    }
    while(!s.empty()) s.pop();
    for(int i = 1; i <= n; i++) {
        while(!s.empty() and a[s.top()] >= a[i]) s.pop();
        l[i] = s.empty() ? 1 : s.top() + 1;
        s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i = n; i >= 1; i--) {
        while(!s.empty() and a[s.top()] > a[i]) s.pop();
        r[i] = s.empty() ? n : s.top() - 1;
        s.push(i);
    }
    for(int i = 1; i <= n; i++) {
        total_min += (long long)(i - l[i] + 1) * (r[i] - i + 1) * a[i];
    }
    cout << total_max - total_min;
}
