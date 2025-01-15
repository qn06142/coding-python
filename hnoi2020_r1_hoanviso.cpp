#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void countingsort(vector<int> & tmp) {
    int cnt[10] = {0};
    for(int i : tmp) {
        cnt[i] ++;
    }
    tmp.clear();
    while(true) {
        bool is = 0;
        for(int i = 9; i >= 0; i--) {
            if(cnt[i] != 0) {
                is = true;
                cnt[i]--;
                tmp.push_back(i);
                break;
            }
        }
        if(not is) {
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string num;
    cin >> num;

    vector<int> digits;
    int sum = 0, zero_count = 0;

    for (char c : num) {
        int digit = c - '0';
        digits.push_back(digit);
        sum += digit;
        if (digit == 0) zero_count++;
    }

    if (zero_count == 0) {
        cout << -1 << endl;
        return 0;
    }
    countingsort(digits);
    if (sum % 3 == 0) {
    } else {
        cout << -1;
        return 0;
    }

    for (int digit : digits) {
        cout << digit;
    }
    cout << endl;
    return 0;
}