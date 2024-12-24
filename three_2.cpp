#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<long long, long long> count_prefix, count_suffix;
    for (long long i = 0; i < n; ++i) {
        count_suffix[a[i]]++;
    }

    long long result = 0;

    for (long long j = 0; j < n; ++j) {
        count_suffix[a[j]]--;

        if (a[j] % k == 0) {
            long long ai = a[j] / k;
            long long ak = a[j] * k;
            result += count_prefix[ai] * count_suffix[ak];
        }

        count_prefix[a[j]]++;
    }

    cout << result << "\n";
    return 0;
}
