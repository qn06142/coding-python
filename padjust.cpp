#include <iostream>
#include <algorithm>
#include <map>
#include<climits>
using namespace std;

map<int, int> count__;
int a[1005];

pair<int, int> find_mistake(int n) {
    for (int i = 0; i < n; ++i) {
        count__[a[i]]++;
    }

    int missing, duplicate;
    duplicate = INT_MIN;
    for(int i = 1; i <= n; i++) {
        if (count__[i] == 0) {
            missing = i;
        }
        if (count__[i] == 2) {
            duplicate = i;
        }
    }
    if(duplicate == INT_MIN) {
        for (int i = 0; i < n; ++i) {
            if(a[i] > n or a[i] < 1) return make_pair(i + 1, missing);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == duplicate) {
            return make_pair(i+1, missing);
        }
    }
    return make_pair(-1, -1);  // This line should never be reached.
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    pair<int, int> result = find_mistake(n);
    cout << result.first << " " << result.second << endl;
    return 0;
}
