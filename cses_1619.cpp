#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    map<int, int> tmap;
    vector<int> times;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;

        tmap[start] = 1;
        tmap[end] = -1;
        times.push_back(start);
        times.push_back(end);
    }

    sort(times.begin(), times.end());

    int curr_ppl = 0;
    int max_ppl = 0;

    for (int t : times) {
        curr_ppl += tmap[t];
        max_ppl = max(max_ppl, curr_ppl);
    }

    cout << max_ppl << endl;

    return 0;
}

