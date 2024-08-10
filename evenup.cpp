#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i];
    }

    stack<int> s;

    for (int i = 0; i < N; ++i) {
        if (!s.empty() && (s.top() + cards[i]) % 2 == 0) {
            s.pop(); // Remove the top card as it forms an even-sum pair with the current card
        } else {
            s.push(cards[i]); // Push the current card onto the stack
        }
    }

    cout << s.size() << endl; // The size of the stack is the minimal number of cards left

    return 0;
}
