#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> A(26);
    for (int i = 0; i < 26; i++) {
        cin >> A[i];
    }

    vector<pair<int, char>> count_chars;
    for (int i = 0; i < 26; i++) {
        if (A[i] > 0) {
            count_chars.push_back({A[i], 'a' + i});
        }
    }

    sort(count_chars.rbegin(), count_chars.rend());

    string result = "";
    int current_count = count_chars[0].first;

    for (auto &p : count_chars) {
        int count = min(p.first, current_count);
        result += string(count, p.second);
        current_count = max(0, count - 1); 
    }

    cout << result << endl;

    return 0;
}