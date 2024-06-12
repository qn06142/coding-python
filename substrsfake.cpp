#include <iostream>
#include <vector>
#include <string>

std::vector<int> computePrefixFunction(const std::string& s) {
    int n = s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

void KMP(const std::string& s, const std::string& pattern) {
    std::vector<int> pi = computePrefixFunction(pattern);
    int n = s.length(), m = pattern.length(), j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != pattern[j])
            j = pi[j-1];
        if (s[i] == pattern[j]) {
            if (j == m - 1) {
                std::cout << i - m + 2 << std::endl;
                j = pi[j];
            } else {
                ++j;
            }
        }
    }
}

int main() {
    std::string inp, inp1;
    std::getline(std::cin, inp);
    std::getline(std::cin, inp1);
    KMP(inp, inp1);
    return 0;
}
