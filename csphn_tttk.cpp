#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, d, k, a, b;
        cin >> n >> d >> k >> a >> b;

        vector<int> sequence;
        sequence.push_back(a);
        sequence.push_back(b);

        set<pair<int, int>> seen;
        seen.insert({a, b});

        int f1 = a, f2 = b;

        while (true) {
            int f_next = (f1 + f2) % d;
            if (seen.count({f2, f_next})) {
                break;
            }
            sequence.push_back(f_next);
            seen.insert({f2, f_next});
            f1 = f2;
            f2 = f_next;
        }

        int period_start = 2; 
        for (int i = 2; i < sequence.size(); ++i) {
            if (sequence[i] == sequence[period_start] && sequence[i + 1] == sequence[period_start + 1]) {
                period_start = i;
                break;
            }
        }
        int period_length = sequence.size() - period_start;

        vector<int> cycle(sequence.begin() + period_start, sequence.end());

        vector<int> count(d, 0);
        for (int num : cycle) {
            count[num]++;
        }

        long long full_cycles = (n - 2) / period_length;
        int remainder = (n - 2) % period_length;

        vector<long long> frequency(d, 0);
        for (int i = 0; i < d; ++i) {
            frequency[i] = count[i] * full_cycles;
        }

        for (int i = 0; i <= remainder; ++i) {
            frequency[cycle[i]]++;
        }

        frequency[a]++;
        frequency[b]++;

        long long accumulated = 0;
        int result = -1;
        for (int i = 0; i < d; ++i) {
            accumulated += frequency[i];
            if (accumulated >= k) {
                result = i;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}
