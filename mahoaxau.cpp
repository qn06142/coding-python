#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {

    freopen("MAHOAXAU.INP", "r", stdin);
    freopen("MAHOAXAU.OUT", "w", stdout);

    string S, A, B;
    long long K;

    cin >> S >> K >> A >> B;

    map<char, vector<char>> cycles;
    for (int i = 0; i < 26; ++i) {
        char start = A[i];
        char current = start;
        vector<char> cycle;
        do {
            cycle.push_back(current);
            current = B[A.find(current)];
        } while (current != start);
        cycles[start] = cycle;
    }

    string result = S;
    for (int i = 0; i < (int)S.size(); ++i) {
        char start = S[i];
        vector<char> &cycle = cycles[start];
        int cycle_len = cycle.size();
        result[i] = cycle[K % cycle_len];
    }

    cout << result << endl;

    return 0;
}