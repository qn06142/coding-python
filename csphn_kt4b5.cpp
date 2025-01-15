#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long permtoind(const vector<int>& p) {
    int n = p.size();
    vector<bool> used(n + 1, false);
    long long index = 0;

    for (int i = 0; i < n; i++) {
        int smaller = 0;
        for (int j = 1; j < p[i]; j++) {
            if (!used[j]) smaller++;
        }
        index += smaller * factorial(n - i - 1);
        used[p[i]] = true;
    }

    return index + 1;
}

vector<int> indtoperm(int n, long long y) {
    vector<int> result;
    vector<int> available;
    for (int i = 1; i <= n; i++) available.push_back(i);

    y--; 
    for (int i = 0; i < n; i++) {
        long long fact = factorial(n - i - 1);
        int pos = y / fact;
        result.push_back(available[pos]);
        available.erase(available.begin() + pos);
        y %= fact;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << permtoind(p) << endl;

    long long y;
    cin >> y;
    vector<int> q = indtoperm(n, y);
    for (int x : q) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}