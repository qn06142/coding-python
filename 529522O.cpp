#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, R;
    cin >> n >> R;
    vector<long long> a(n + 1);
    vector<long long> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }

    long long result = -1e18;  
    set<long long> s;

    s.insert(0);

    for (int i = 1; i <= n; i++) {

        if (i > R) {
            s.erase(prefix[i - R - 1]);
        }

        result = max(result, prefix[i] - *s.begin());

        s.insert(prefix[i]);
    }

    cout << result << endl;
    return 0;
}