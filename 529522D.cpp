#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long delta;
    cin >> n >> delta;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    deque<int> maxDeque, minDeque;
    int left = 0, maxLength = 0;

    for (int right = 0; right < n; ++right) {
        while (!maxDeque.empty() && a[maxDeque.back()] <= a[right]) maxDeque.pop_back();
        maxDeque.push_back(right);

        while (!minDeque.empty() && a[minDeque.back()] >= a[right]) minDeque.pop_back();
        minDeque.push_back(right);

        while (a[maxDeque.front()] - a[minDeque.front()] > delta) {
            if (maxDeque.front() == left) maxDeque.pop_front();
            if (minDeque.front() == left) minDeque.pop_front();
            ++left;
        }

        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;
    return 0;
}