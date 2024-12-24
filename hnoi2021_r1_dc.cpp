#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("DC.INP", "r", stdin);
    freopen("DC.OUT", "w", stdout);

    int N, K;
    cin >> N >> K;

    map<long long, int> changes; 

    for (int i = 0; i < N; ++i) {
        long long a, b;
        cin >> a >> b;

        changes[a]++;  
        changes[b + 1]--; 
    }

    long long current_count = 0;
    long long last_position = 0;
    long long result = 0;

    for (auto it = changes.begin(); it != changes.end(); ++it) {
        long long position = it->first;

        if (current_count == K) {
            result += position - last_position; 
        }

        current_count += it->second;
        last_position = position;
    }

    cout << result << "\n";
    return 0;
}
