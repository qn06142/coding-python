#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> pre(n + 1, 0);
    vector<char> st;  
    for (int i = 1; i <= n; i++){
        char c = s[i - 1];
        while(!st.empty() && st.back() > c){
            st.pop_back();
        }
        if (st.empty() || st.back() < c){
            st.push_back(c);
            pre[i] = pre[i - 1] + 1;
        } else {
            pre[i] = pre[i - 1];
        }
    }

    vector<int> suf(n + 2, 0);
    st.clear();

    for (int i = n; i >= 1; i--){
        char c = s[i - 1];
        while(!st.empty() && st.back() > c){
            st.pop_back();
        }
        if (st.empty() || st.back() < c){
            st.push_back(c);
            suf[i] = suf[i + 1] + 1;
        } else {
            suf[i] = suf[i + 1];
        }
    }

    while(q--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        if(l > 1) ans += pre[l - 1];
        if(r < n) ans += suf[r + 1];
        cout << ans << "\n";
    }

    return 0;
}