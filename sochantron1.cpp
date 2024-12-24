#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindromeEven(int num) {
    string s = to_string(num);
    int n = s.size();
    if ((s[0] - '0') % 2 != 0 || (s[n - 1] - '0') % 2 != 0)
        return false; // First or last digit not even
    return true;
}

int countEvenRoundNumbers(int N) {
    int count = 0;
    for (int i = 2; i < N; i += 2) { // Only check even numbers
        if (isPalindromeEven(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countEvenRoundNumbers(N) << endl;
    return 0;
}
