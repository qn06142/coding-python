#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

string getHalf(const string &s) {
    int len = s.size();
    return s.substr(0, len / 2);
}

bool isRepeat(const string &s) {
    int len = s.size();
    if (len % 2 != 0) return false;
    string half = s.substr(0, len / 2);
    return half + half == s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string z;
    cin >> z;

    unordered_set<string> solutions;

    for (int i = 0; i < n; ++i) {
        string left = z.substr(0, i);
        string right = z.substr(i + 1);
        string t = left + right;

        if (isRepeat(t)) {
            solutions.insert(getHalf(t));
        }
    }

    if (solutions.empty()) {
        cout << "No Solution\n";
    } else if (solutions.size() > 1) {
        cout << "Multiple Solutions\n";
    } else {
        cout << *solutions.begin() << '\n';
    }

    return 0;
}
