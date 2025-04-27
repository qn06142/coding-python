#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Project {
    long long a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Project> group1, group2, projects(n);

    for (int i = 0; i < n; i++) {
        cin >> projects[i].a;
    }
    for (int i = 0; i < n; i++) {
        cin >> projects[i].b;
    }

    for (int i = 0; i < n; i++) {
        if (projects[i].a <= projects[i].b)
            group1.push_back(projects[i]);
        else
            group2.push_back(projects[i]);
    }

    sort(group1.begin(), group1.end(), [](const Project &p1, const Project &p2) {
        return p1.a < p2.a;
    });

    sort(group2.begin(), group2.end(), [](const Project &p1, const Project &p2) {
        return p1.b > p2.b;
    });

    vector<Project> order;
    for (auto &p : group1)
        order.push_back(p);
    for (auto &p : group2)
        order.push_back(p);

    long long S = 0;    
    long long ans = 0;  
    for (auto &p : order) {
        ans = max(ans, p.a - S);
        S += (p.b - p.a);
    }

    cout << ans << "\n";
    return 0;
}