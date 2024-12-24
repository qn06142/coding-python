#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    std::string string = "010001000110000010110111001001111010101000100010001000101000010110100000100001011";
    for (size_t i = 8; i < string.length(); ++i) {
        char ch = static_cast<char>(std::stoi(string.substr(i - 8, 8), nullptr, 2));
        if (std::islower(ch)) {
            std::cout << ch;
        }
    }

    std::ifstream f("wordlisteng.txt");
    std::set<std::string> stor;
    std::string word;
    while (f >> word) {
        stor.insert(word);
    }

    for (size_t i = 0; i <= string.length(); ++i) {
        std::vector<char> combination;
        for (size_t j = 0; j < string.length(); ++j) {
            combination.push_back(string[j]);
            if (combination.size() == i) {
                std::string comb_str(combination.begin(), combination.end());
                if (stor.find(comb_str) != stor.end()) {
                    std::cout << comb_str << std::endl;
                }
            }
        }
        combination.clear();
    }

    return 0;
}

