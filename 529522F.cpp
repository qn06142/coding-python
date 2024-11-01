#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, L;
    cin >> n >> L;
    vector<long long> a(n + 1);
    vector<long long> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];  
    }

    long long result = -1e18;  
    set<long long> s;

    for (int i = L; i <= n; i++) {

        s.insert(prefix[i - L]);

        result = max(result, prefix[i] - *s.begin());
    }

    cout << result << endl;
    return 0;
}