#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#ifdef DEBUG
#define DEBUG_PRINT(x) cout << x
#else
#define DEBUG_PRINT(x) 
#endif
int cnt[(int) 1e6 + 5];
int countVisiblePairs(const vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    int count = 0;


    for (int i = 0; i < n; i++) {

        while (!st.empty() && heights[st.top()] < heights[i]) {
            if(i == 4) {
                //cout << cnt[heights[st.top()]] << endl;
            } 
            if(cnt[heights[st.top()]] > 0) {
                count ++;
                //cout << "normal " << st.top() <<  ' ' << i << endl;
            }
            cnt[heights[st.top()]] = 0;
            st.pop();
        }

        if (!st.empty()) {
            //cout << "top " << i  << ' '<< st.top() << endl;
            count++;
        }
        st.push(i);
        cnt[heights[i]]++;
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    int result = countVisiblePairs(heights);
    cout << result << endl;
    return 0;
}
