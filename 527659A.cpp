#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string findSmallestNumber(int n, const vector<char> &digits) {
    // Create a queue for BFS and a set to keep track of remainders
    queue<pair<string, int>> q; // Pair stores the number as a string and its remainder modulo n
    unordered_set<int> visited;
    
    // Initialize the queue with digits (excluding '0' if other digits exist)
    for (char d : digits) {
        if (d != '0') {
            int remainder = (d - '0') % n;
            string num(1, d);
            q.push({num, remainder});
            visited.insert(remainder);
        }
    }
    
    while (!q.empty()) {
        auto [curr, curr_remainder] = q.front();
        q.pop();
        
        // Check if the current number is divisible by n
        if (curr_remainder == 0) {
            return curr;
        }
        
        // Generate new numbers by appending each digit
        for (char d : digits) {
            string next_num = curr + d;
            int next_remainder = (curr_remainder * 10 + (d - '0')) % n;
            if (visited.find(next_remainder) == visited.end()) {
                q.push({next_num, next_remainder});
                visited.insert(next_remainder);
            }
        }
    }
    
    return "0";
}

int main() {
    int n;
    string digits_str;
    
    // Input reading
    cin >> n;
    cin >> digits_str;
    
    vector<char> digits(digits_str.begin(), digits_str.end());
    
    // Find the smallest number
    cout << findSmallestNumber(n, digits) << endl;
    
    return 0;
}
