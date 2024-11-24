#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

long long countValidSubstrings(const string& s) {
    unordered_set<char> required_chars = {'A', 'B', 'C', 'D', 'E', 'F'};
    int required_count = required_chars.size();
    
    int n = s.length();
    int left = 0;
    unordered_map<char, int> char_count;
    int unique_count = 0;
    long long valid_substrings = 0;
    
    for (int right = 0; right < n; ++right) {
        if (required_chars.count(s[right])) {
            char_count[s[right]]++;
            if (char_count[s[right]] == 1) {
                unique_count++;
            }
        }
        
        while (unique_count == required_count) {
            valid_substrings += n - right;
            if (required_chars.count(s[left])) {
                char_count[s[left]]--;
                if (char_count[s[left]] == 0) {
                    unique_count--;
                }
            }
            left++;
        }
    }
    
    return valid_substrings;
}

int main() {
    int m;
    string s;
    cin >> m >> s;
    
    long long result = countValidSubstrings(s);
    cout << result << endl;
    
    return 0;
}
