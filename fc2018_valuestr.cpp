#include <iostream>
#include <vector>
using namespace std;

bool isValid(const string& s, int len, long long C) {
    vector<int> count(26, 0);
    long long value = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'b') {
            value += count['a' - 'a'];
        }
        count[s[i] - 'a']++;
    }
    if (value <= C) return true;
    for (int i = len; i < s.size(); ++i) {
        count[s[i - len] - 'a']--;
        if (s[i - len] == 'a') {
            value -= count['b' - 'a'];
        }
        if (s[i] == 'b') {
            value += count['a' - 'a'];
        }
        count[s[i] - 'a']++;
        if (value <= C) return true;
    }
    return false;
}

int main() {
    int N;
    long long C;
    string S;
    cin >> N >> C >> S;

    int left = 1, right = N, result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isValid(S, mid, C)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << result << endl;
    return 0;
}
