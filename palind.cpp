#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


bool isPalindrome(const string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}


string makePalindrome(string left, bool oddLength) {
    string result = left;
    if (oddLength) left.pop_back();
    reverse(left.begin(), left.end());
    result += left;
    return result;
}


string findNextPalindrome(const string &a) {
    int n = a.size();
    string left = a.substr(0, (n + 1) / 2); 
    string palindrome = makePalindrome(left, n % 2 != 0);

    
    if (palindrome >= a) return palindrome;

    
    int i = left.size() - 1;
    while (i >= 0 && left[i] == '9') {
        left[i] = '0';
        i--;
    }
    if (i < 0) left = "1" + left; 
    else left[i]++;

    
    return makePalindrome(left, n % 2 != 0);
}

int main() {
    string a;
    cin >> a;
    cout << findNextPalindrome(a) << endl;
    return 0;
}
