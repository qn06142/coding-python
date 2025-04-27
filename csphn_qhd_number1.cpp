#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string trimLeadingZeros(const string &s) {
    int idx = 0;
    while(idx < s.size() && s[idx] == '0')
        idx++;
    string trimmed = s.substr(idx);
    return trimmed == "" ? "0" : trimmed;
}

bool better(const string &s1, const string &s2) {
    string t1 = trimLeadingZeros(s1);
    string t2 = trimLeadingZeros(s2);
    if(t1.size() != t2.size())
        return t1.size() > t2.size();
    return t1 > t2; 
}

string best = "";  

void backtrack(const string &a, const string &b, int i, int j, string current) {
    if(i == a.size() || j == b.size()) {

        if(better(current, best))
            best = current;
        return;
    }

    if(a[i] == b[j])
        backtrack(a, b, i + 1, j + 1, current + a[i]);

    backtrack(a, b, i + 1, j, current);

    backtrack(a, b, i, j + 1, current);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    backtrack(a, b, 0, 0, "");

    if(best == "")
        best = "0";

    cout << best << "\n";
    return 0;
}