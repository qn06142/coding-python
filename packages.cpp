#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> solve(int T, vector<pair<int, int>> store, vector<vector<int>> weights) {
    vector<int> results;

    for (int t = 0; t < T; ++t) {
        int n = store[t].first;
        int q = store[t].second;

        multiset<int> bags; 

        for (int w : weights[t]) {
            auto it = bags.lower_bound(q - w + 1); 
            if (it != bags.begin()) {
                --it; 
                int tmp = *it + w;
                bags.erase(it); 
                bags.insert(tmp); 
            } else {
                bags.insert(w); 
            }
        }

        results.push_back(bags.size());
    }

    return results;
}

int main() {
    int T;
    cin >> T;

    vector<pair<int, int>> store(T);
    vector<vector<int>> weights(T);

    for (int t = 0; t < T; ++t) {
        int n, q;
        cin >> n >> q;
        store[t] = {n, q};
        weights[t].resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> weights[t][i];
        }
    }

    vector<int> results = solve(T, store, weights);

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}