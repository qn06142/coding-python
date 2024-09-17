#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Counter {
    int a; // Time to handle one luggage
    int b; // Time to print boarding passes
};

// Comparator to sort counters by efficiency (first by `a[i]`, then by `b[i]`)
bool compare(const Counter &c1, const Counter &c2) {
    return c1.a + c1.b < c2.a + c2.b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    vector<Counter> counters(n);
    for (int i = 0; i < n; ++i) {
        cin >> counters[i].a >> counters[i].b;
    }

    // Sort counters by efficiency to handle luggage
    sort(counters.begin(), counters.end(), compare);

    // Total time calculation
    long long total_time = 0;

    // First, handle the people: each counter will need to print boarding passes
    for (int i = 0; i < min(n, m); ++i) {
        total_time += counters[i].b;
    }

    // Now distribute the luggage across the counters with minimal `a[i]`
    for (int i = 0; i < n && p > 0; ++i) {
        int luggage_at_this_counter = min(p, m);  // We can't assign more luggage than people
        total_time += luggage_at_this_counter * counters[i].a;
        p -= luggage_at_this_counter;
        m -= luggage_at_this_counter;
    }

    // Output the minimal total time
    cout << total_time << '\n';

    return 0;
}
