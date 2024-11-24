#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 100000; 

int arr[MAXN];
int l[MAXN];
int r[MAXN];

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        stack<int> s;

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            l[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            r[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        int maxStrength = 0, bestStart = 0, bestEnd = 0;
        for (int i = 0; i < n; ++i) {
            int strength = arr[i] * (r[i] - l[i] - 1);
            if (strength > maxStrength) {
                maxStrength = strength;
                bestStart = l[i] + 1;
                bestEnd = r[i] - 1;
            }
        }

        cout << maxStrength << " " << bestStart + 1 << " " << bestEnd + 1 << endl; 
    }

    return 0;
}