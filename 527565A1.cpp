#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfNumber;
    TrieNode() : isEndOfNumber(false) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    bool insert(const string& number) {
        TrieNode* node = root;
        bool isPrefix = false;

        for (char c : number) {
            if (node->isEndOfNumber) {

                isPrefix = true;
            }
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }

        if (!node->children.empty()) {

            isPrefix = true;
        }

        node->isEndOfNumber = true;
        return isPrefix;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Trie trie;
        vector<string> numbers(n);
        bool consistent = true;

        for (int i = 0; i < n; ++i) {
            cin >> numbers[i];
        }

        for (const string& number : numbers) {
            if (trie.insert(number)) {
                consistent = false;
                break;
            }
        }

        cout << (consistent ? "YES" : "NO") << endl;
    }

    return 0;
}