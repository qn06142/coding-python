#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <vector>

using namespace std;

string best_backtrack = ""; 

string trimLeadingZeros(const string &s) {
    size_t idx = 0;
    while (idx < s.size() && s[idx] == '0') {
        idx++;
    }
    if (idx == s.size()) { 
        return "0";
    }
    return s.substr(idx);
}

bool better(const string &s1, const string &s2) {
     if (s1.empty() && s2.empty()) return false;

     if (s1.empty()) return false;
     if (s2.empty()) return true;

    string t1 = trimLeadingZeros(s1);
    string t2 = trimLeadingZeros(s2);
    if (t1.size() != t2.size()) {
        return t1.size() > t2.size();
    }
    return t1 > t2; 
}

void backtrack(const string &a, const string &b, int i, int j, string current) {

    if (i == a.size() || j == b.size()) {
        if (better(current, best_backtrack)) {
            best_backtrack = current;
        }
        return;
    }

     if (better(current, best_backtrack)) {
            best_backtrack = current;
     }

    if (a[i] == b[j]) {
        backtrack(a, b, i + 1, j + 1, current + a[i]);
    }

    backtrack(a, b, i + 1, j, current);

    backtrack(a, b, i, j + 1, current);

     if (better(current, best_backtrack)) {
            best_backtrack = current;
     }
}

string solve_dp(const string& a, const string& b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    if (dp[0][0] == 0) return "0"; 

    const int num_digits = 10;
    vector<vector<int>> next_a(n + 1, vector<int>(num_digits, -1));
    vector<vector<int>> next_b(m + 1, vector<int>(num_digits, -1));

    for (int i = n - 1; i >= 0; i--) {
        for (int d = 0; d < num_digits; d++) {
            next_a[i][d] = next_a[i + 1][d];
        }
        if (a[i] >= '0' && a[i] <= '9') {
             next_a[i][a[i] - '0'] = i;
        }
    }

    for (int j = m - 1; j >= 0; j--) {
        for (int d = 0; d < num_digits; d++) {
            next_b[j][d] = next_b[j + 1][d];
        }
         if (b[j] >= '0' && b[j] <= '9') {
             next_b[j][b[j] - '0'] = j;
         }
    }

    string res = "";
    int current_i = 0;
    int current_j = 0;
    int remain = dp[0][0];

    while (remain > 0) {
        bool found_digit = false;
        for (int d = 9; d >= 0; d--) { 
            int pos_a = next_a[current_i][d];
            int pos_b = next_b[current_j][d];

            if (pos_a != -1 && pos_b != -1) {

                if (dp[pos_a + 1][pos_b + 1] >= remain - 1) {
                    res.push_back('0' + d);
                    current_i = pos_a + 1;
                    current_j = pos_b + 1;
                    remain--;
                    found_digit = true;
                    break; 
                }
            }
        }
         if (!found_digit && remain > 0) {

             break;
        }
    }

    return res.empty() ? "0" : res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    const int THRESHOLD = 20; 

    string final_result;

    if (n + m <= THRESHOLD) {

        best_backtrack = ""; 
        backtrack(a, b, 0, 0, "");

        if (best_backtrack.empty()) {
            final_result = "0";
        } else {

            final_result = best_backtrack;

        }

    } else {

        final_result = solve_dp(a, b);

    }

    cout << final_result << "\n";

    return 0;
}