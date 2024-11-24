#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int left;        
    int right;       
    long long sum;   
    long long first; 
    long long last;  
    Node *left_child;
    Node *right_child;

    Node(int arr[], int l, int r) {
        left = l;
        right = r;
        first = last = 0; 
        if (l == r) { 
            sum = arr[l];
        } else { 
            int mid = (l + r) / 2;
            left_child = new Node(arr, l, mid);
            right_child = new Node(arr, mid + 1, r);
            sum = left_child->sum + right_child->sum;
        }
    }

    void add(int l, int r, long long X) {
        propagate();
        if (r < left || right < l) {
            return; 
        } else if (l <= left && right <= r) {

            int first_item_offset = (left - l) + 1;
            int last_item_offset = (right - l) + 1;
            first += X * first_item_offset;
            last += X * last_item_offset;
            propagate();
        } else {
            left_child->add(l, r, X);
            right_child->add(l, r, X);
            sum = left_child->sum + right_child->sum; 
        }
    }

    long long query(int l, int r) {
        propagate();
        if (r < left || right < l) {
            return 0; 
        } else if (l <= left && right <= r) {
            return sum; 
        } else {

            return left_child->query(l, r) + right_child->query(l, r);
        }
    }

    void propagate() {
        int items_count = (right - left) + 1;
        sum += ((first + last) * items_count) / 2; 
        if (right != left) { 
            int step = (last - first) / (items_count - 1);
            int mid = (items_count - 1) / 2;
            left_child->first += first;
            left_child->last += first + (step * mid);
            right_child->first += first + (step * (mid + 1));
            right_child->last += last;
        }

        first = last = 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n;
    int arr[n + 1]; 
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    Node *root = new Node(arr, 1, n); 

    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            long long v;
            cin >> l >> r >> v;
            root->add(l, r, v); 
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << root->query(l, r) << '\n'; 
        }
    }

    return 0;
}