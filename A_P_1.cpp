#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first; 
    }

    sort(movies.begin(), movies.end()); 

    multiset<int> end_times; 
    for (int i = 0; i < k; i++) {
        end_times.insert(0); 
    }

    int count = 0;
    for (const auto& movie : movies) {
        auto it = end_times.upper_bound(movie.second); 
        if (it != end_times.begin()) {
            --it;
            end_times.erase(it); 
            end_times.insert(movie.first); 
            count++;
        }
    }

    cout << count << endl;

    return 0;
}