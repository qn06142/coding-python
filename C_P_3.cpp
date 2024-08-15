#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int max_len = 0, count = 0;

    int left = 0, right = 0;
    vector<int> valid_ends; 

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') left++;
        else right++;

        if (left == right) {
            int len = 2 * right;
            if (len > max_len) {
                max_len = len;
                count = 1;
                valid_ends.clear();
                valid_ends.push_back(i);
            } else if (len == max_len) {
                if (valid_ends.empty() || i - max_len > valid_ends.back()) {
                    count++;
                    valid_ends.push_back(i);
                }
            }
        } else if (right > left) {
            left = right = 0;
            valid_ends.clear();
        }
    }

    left = right = 0;
    valid_ends.clear();

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') left++;
        else right++;

        if (left == right) {
            int len = 2 * left;
            if (len > max_len) {
                max_len = len;
                count = 1;
                valid_ends.clear();
                valid_ends.push_back(i);
            } else if (len == max_len) {
                if (valid_ends.empty() || i + max_len < valid_ends.back()) {
                    count++;
                    valid_ends.push_back(i);
                }
            }
        } else if (left > right) {
            left = right = 0;
            valid_ends.clear();
        }
    }

    if (max_len == 0) count = 1; 

    cout << max_len << " " << count << endl;
    return 0;
}