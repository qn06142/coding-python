#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    const int MOD = 2023;
    unordered_map<int, int> remainder_count;
    remainder_count[0] = 1; 

    long long result = 0;
    int current_remainder = 0;
    int power_of_ten = 1;

    for (int i = n - 1; i >= 0; --i) {
        int digit = s[i] - '0';
        current_remainder = (current_remainder + digit * power_of_ten) % MOD;
        power_of_ten = (power_of_ten * 10) % MOD;

        result += remainder_count[current_remainder];
        remainder_count[current_remainder]++;
    }

    cout << result << "\n";
    return 0;
}