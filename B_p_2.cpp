#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int l = 0, r = 0;
    int maxLength = 0, count = 1;
    int prefix_sum = 0;

    while (r < n) {

        if (s[r] == '(') {
            prefix_sum += 1;
        } else {
            prefix_sum -= 1;
        }

        while (prefix_sum < 0 && l <= r) {
            if (s[l] == '(') {
                prefix_sum -= 1;
            } else {
                prefix_sum += 1;
            }
            l++;
        }

        if (prefix_sum == 0) {
            int length = r - l + 1;
            if (length > maxLength) {
                maxLength = length;
                count = 1;
            } else if (length == maxLength) {
                count++;
            }
        }

        r++;
    }

    if (maxLength == 0) {
        cout << "0 1" << endl;
    } else {
        cout << maxLength << " " << count << endl;
    }

    return 0;
}