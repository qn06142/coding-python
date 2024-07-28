#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> heights = {0, 4, 2, 3, 4, 3};
    stack<int> s;
    int n = heights.size();
    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        while(!s.empty() and heights[i] < heights[s.top()]) {
            s.pop();
        }
        int h = i - 
        cout <<(s.empty() ? -1 : s.top()) << ' ';
        s.push(i);
    }
}