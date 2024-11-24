#include <bits/stdc++.h>
using namespace std;

const int MAX_SALARY = 100000;
int offset = 0;  // Global offset for A/S operations
int leftCount = 0;  // Employees who left
map<int, int> salaryCount;  // To store counts of each salary level

void addEmployee(int salary) {
    salary -= offset;
    salaryCount[salary]++;
}

void increaseAll(int value) {
    offset += value;
}

void decreaseAll(int value) {
    offset -= value;
}

int findKthHighest(int k) {
    int count = 0;
    for (auto it = salaryCount.rbegin(); it != salaryCount.rend(); ++it) {
        count += it->second;
        if (count >= k) return it->first + offset;
    }
    return -1;  // Not enough employees
}

void removeLeftEmployees(int X) {
    // Remove employees with effective salary below X
    for (auto it = salaryCount.begin(); it != salaryCount.end();) {
        int actualSalary = it->first + offset;
        if (actualSalary < X) {
            leftCount += it->second;
            it = salaryCount.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, X;
    cin >> N >> X;
    vector<string> results;

    for (int i = 0; i < N; ++i) {
        char op;
        int K;
        cin >> op >> K;

        if (op == 'I') {
            addEmployee(K);
        } else if (op == 'A') {
            increaseAll(K);
            removeLeftEmployees(X);  // Check for employees who should leave
        } else if (op == 'S') {
            decreaseAll(K);
            removeLeftEmployees(X);  // Check for employees who should leave
        } else if (op == 'F') {
            int result = findKthHighest(K);
            results.push_back(to_string(result));
        }
    }

    // Print all results for F queries
    for (const auto &res : results) {
        cout << res << "\n";
    }
    // Print the number of employees who left
    cout << leftCount << "\n";

    return 0;
}
