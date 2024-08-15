#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> W(N);
    int original_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
        original_sum += W[i];
    }
    
    int added_mass = 0;
    
    for (int i = 0; i < N; ++i) {
        if (!pq.empty()) {
            int lightest = pq.top();
            pq.pop();
            added_mass += lightest;
            pq.push(lightest * 2);
        }
        pq.push(W[i]);
    }
    
    cout << added_mass << endl;
    
    return 0;
}
