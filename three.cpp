#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main() {
    int n, k;
    string input;
    getline(cin, input);
    istringstream iss(input);
    iss >> n >> k;

    vector<int> a(n + 1, 0);
    getline(cin, input);
    istringstream iss2(input);
    string token;
    int i = 1;
    while (iss2 >> token) {
        int count = 0;
        for (char c : token) {
            if (c == '3') {
                count++;
            }
        }
        a[i++] = count;
    }

    int ans = 0;
    int curr = 0;
    int j = 1;
    for (i = 1; i <= n; i++) {
        curr += a[i];
        while (curr >= k) {
            curr -= a[j];
            j++;
        }
        if (i >= j) {
            ans += i - j + 1;
        }
    }

    cout << ans << endl;
    return 0;
}

