#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool isSubsequence(const string& s, const string& t) {
    size_t j = 0;
    for (size_t i = 0; i < t.size() && j < s.size(); ++i) {
        if (s[j] == t[i]) {
            ++j;
        }
    }
    return j == s.size();
}

void generateSubsequences(const string& x, int n, int index, string current, set<string>& result) {
    if (current.size() == n) {
        result.insert(current);
        return;
    }
    if (index == x.size()) {
        return;
    }

    generateSubsequences(x, n, index + 1, current + x[index], result);

    generateSubsequences(x, n, index + 1, current, result);
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;

    string x, y;
    cin >> x >> y;

    vector<string> s(m);
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }

    set<string> subsequences;
    generateSubsequences(x, n, 0, "", subsequences);

    vector<string> validSubsequences;
    for (const string& subseq : subsequences) {
        if (!isSubsequence(subseq, y)) {
            validSubsequences.push_back(subseq);
        }
    }

    sort(validSubsequences.begin(), validSubsequences.end());

    for (const string& si : s) {
        if (!isSubsequence(si, x) || isSubsequence(si, y)) {
            cout << -1 << endl;
        } else {
            auto it = lower_bound(validSubsequences.begin(), validSubsequences.end(), si);
            int position = it - validSubsequences.begin() + 1;
            cout << position % k << endl;
        }
    }

    return 0;
}