#include <iostream>
#include <vector>
#include <stack>

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

    for (int i = 0; i < n; ++i) {

        int left_a = prev_greater[i] + 1;
        int right_a = next_greater[i] - 1;

        int left_b = prev_lesser[i] + 1;
        int right_b = next_lesser[i] - 1;

        if (a[i] == b[i]) {
            long long valid_a = (i - left_a + 1) * (right_a - i + 1);
            long long valid_b = (i - left_b + 1) * (right_b - i + 1);
            count = (count + valid_a * valid_b) % MOD;
        }
    }

    cout << count << endl;

    return 0;
}