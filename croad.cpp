#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n + 1), prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= k; 
    }

    unordered_map<long long, int> mp; 
    mp[0] = 0; 
    int max_len = 0, start = -1, end = -1;

    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i]; 
        if (mp.count(prefix[i])) {

            int len = i - mp[prefix[i]];
            if (len > max_len) {
                max_len = len;
                start = mp[prefix[i]] + 1; 
                end = i; 
            }
        } else {

            mp[prefix[i]] = i;
        }
    }

    if (max_len > 0) {
        cout << start << " " << end - start + 1 << endl; 
    } else {
        cout << 0 << endl; 
    }

    return 0;
}