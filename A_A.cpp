#include <bits/stdc++.h>
using namespace std;

struct Task {
    int a, t, idx;
};

bool can_solve_k_tasks(vector<Task>& tasks, int n, int T, int k) {
    vector<int> chosen_tasks;
    int total_time = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        if (tasks[i].a >= k) {
            chosen_tasks.push_back(tasks[i].t);
        }
    }
    if (chosen_tasks.size() < k) return false;

    sort(chosen_tasks.begin(), chosen_tasks.end());
    for (int i = 0; i < k; ++i) {
        total_time += chosen_tasks[i];
        if (total_time > T) return false;
    }
    return true;
}

int main() {
    int n, T;
    cin >> n >> T;
    vector<Task> tasks(n);
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].a >> tasks[i].t;
        tasks[i].idx = i + 1;
    }

    int left = 0, right = n, best_k = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (can_solve_k_tasks(tasks, n, T, mid)) {
            best_k = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    vector<pair<int, int>> valid_tasks;
    for (int i = 0; i < n; ++i) {
        if (tasks[i].a >= best_k) {
            valid_tasks.push_back({tasks[i].t, tasks[i].idx});
        }
    }

    sort(valid_tasks.begin(), valid_tasks.end());
    int total_time = 0;
    vector<int> result;
    for (int i = 0; i < best_k; ++i) {
        total_time += valid_tasks[i].first;
        result.push_back(valid_tasks[i].second);
    }

    cout << best_k << "\n";
    cout << best_k << "\n";
    for (int i : result) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}