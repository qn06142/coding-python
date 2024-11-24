#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int k;
    cin >> k;
    string s;
    cin >> s;

    unordered_map<int, long long> count;  
    count[0] = 1;  
    long long prefix = 0;  
    int result = 0;

    for (char c : s) {

        if (c == '1') {
            prefix++;
        }

        if (count.find(prefix - k) != count.end()) {
            result += count[prefix - k];
        }

        count[prefix]++;
    }

    cout << result << '\n';

    return 0;
}