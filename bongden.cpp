#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Bulb {
    int A, B;
};

bool compare(const Bulb &x, const Bulb &y) {
    return x.A < y.A; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Bulb> bulbs(N);
    for (int i = 0; i < N; ++i) {
        cin >> bulbs[i].A;
    }
    for (int i = 0; i < N; ++i) {
        cin >> bulbs[i].B;
    }

    sort(bulbs.begin(), bulbs.end(), compare);

    multiset<int> active;
    long long sum = 0, max_score = 0;

    for (int i = 0; i < N; ++i) {
        if ((int)active.size() < bulbs[i].A) {

            active.insert(bulbs[i].B);
            sum += bulbs[i].B;
        } else if (!active.empty() && bulbs[i].B > *active.begin()) {

            sum += bulbs[i].B - *active.begin();
            active.erase(active.begin());
            active.insert(bulbs[i].B);
        }

        max_score = max(max_score, sum);
    }

    cout << max_score << "\n";
    return 0;
}