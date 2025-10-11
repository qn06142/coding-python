#include <bits/stdc++.h>
using namespace std;

multiset<string> bag;

bool contains(const string &big, const string &sub) {
    return big.find(sub) != string::npos;
}

int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        bag.insert(s);
    }

    int q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op >> s;
        if (op == 'i') {
            bag.insert(s);
        } else if (op == 'e') {
            auto it = bag.find(s);
            if (it != bag.end()) bag.erase(it);
        } else if (op == 'q') {
            int count = 0;
            for (const string &x : bag) {
                if (contains(x, s)) count++;
            }
            cout << count << '\n';
        }
    }
}
