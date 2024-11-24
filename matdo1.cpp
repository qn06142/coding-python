#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    #ifdef ONLINE_JUDGE
    freopen("MatDo.Inp", "r", stdin);
    freopen("MatDo.Out", "w", stdout);
    #endif
    string S;
    cin >> S;
    int maxLen = 0;
    int n = S.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            unordered_map<char, int> freq;

            for (int k = i; k <= j; ++k) {
                freq[S[k]]++;
            }

            bool isValid = false;
            for (auto& [ch, count] : freq) {
                int otherCount = 0;
                for (auto& [otherCh, otherCountVal] : freq) {
                    if (otherCh != ch) otherCount += otherCountVal;
                }
                if (count > otherCount) {
                    isValid = true;
                    break;
                }
            }

            if (isValid) {
                if(j - i + 1 > maxLen)
                cerr << i << ' ' << j << '\n';
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    cout << maxLen << endl;
    return 0;
}
