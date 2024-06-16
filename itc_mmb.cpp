#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const long long MOD = 1234567891;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Precompute the next greater and previous greater elements in array a
    vector<int> next_greater(n, n), prev_greater(n, -1);
    stack<int> s;
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && a[s.top()] < a[i]) {
            next_greater[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    while (!s.empty()) s.pop();
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            prev_greater[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    // Precompute the next lesser and previous lesser elements in array b
    vector<int> next_lesser(n, n), prev_lesser(n, -1);
    
    while (!s.empty()) s.pop();
    
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && b[s.top()] > b[i]) {
            next_lesser[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    
    while (!s.empty()) s.pop();
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && b[s.top()] >= b[i]) {
            prev_lesser[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    long long count = 0;
    for(int i = 1; i <= n; i++) {
        count += r[i] * l[i];
    }

    cout << count << endl;

    return 0;
}
