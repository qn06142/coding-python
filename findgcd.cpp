#include<bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000000000;

struct Node {
    int gcd;
    Node* left;
    Node* right;
    Node() : gcd(0), left(nullptr), right(nullptr) {}
};

class SegmentTree {
public:
    SegmentTree() {
        root = new Node();
    }

    void update(int pos, int value, int left = 0, int right = MAX_VAL, Node* node = nullptr) {
        if (node == nullptr) {
            node = root;
        }

        if (left == right) {
            node->gcd = value;
            return;
        }

        int mid = (left + right) / 2;
        if (pos <= mid) {
            if (node->left == nullptr) {
                node->left = new Node();
            }
            update(pos, value, left, mid, node->left);
        } else {
            if (node->right == nullptr) {
                node->right = new Node();
            }
            update(pos, value, mid + 1, right, node->right);
        }

        node->gcd = gcd(node->left ? node->left->gcd : 0, node->right ? node->right->gcd : 0);
    }

    int query() {
        return root->gcd;
    }

private:
    Node* root;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<pair<int, int>> operations(N);
    for (int i = 0; i < N; ++i) {
        int t, x;
        cin >> t >> x;
        operations[i] = {t, x};
    }

    SegmentTree segment_tree;
    map<int, int> count;
    
    for (const auto& op : operations) {
        int t = op.first;
        int x = op.second;
        
        if (t == 1) {
            count[x]++;
            if (count[x] == 1) {
                segment_tree.update(x, x);
            }
        } else if (t == 2) {
            count[x]--;
            if (count[x] == 0) {
                segment_tree.update(x, 0);
            }
        }
        
        int current_gcd = segment_tree.query();
        cout << (current_gcd != 0 ? current_gcd : 1) << '\n';
    }

    return 0;
}
