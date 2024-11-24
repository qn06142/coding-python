#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    k += k;
    deque<int> max_deque, min_deque;
    int max_score = 0;

    for (int i = 0; i < n; ++i) {

        while (!max_deque.empty() && max_deque.front() < i - k) {
            max_deque.pop_front();
        }
        while (!min_deque.empty() && min_deque.front() < i - k) {
            min_deque.pop_front();
        }

        while (!max_deque.empty() && a[max_deque.back()] <= a[i]) {
            max_deque.pop_back();
        }
        max_deque.push_back(i);

        while (!min_deque.empty() && a[min_deque.back()] >= a[i]) {
            min_deque.pop_back();
        }
        min_deque.push_back(i);

        if (i >= k) {

            int max_value = a[max_deque.front()];
            int min_value = a[min_deque.front()];
            max_score = max(max_score, max_value - min_value);
        }
    }

    cout << max_score << endl;

    return 0;
}