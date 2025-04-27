#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<long long>> grid(m, vector<long long>(n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> height(m, vector<int>(n, 0));
    for (int j = 0; j < n; j++){
        height[0][j] = 1;
    }
    for (int i = 1; i < m; i++){
        for (int j = 0; j < n; j++){
            if(grid[i][j] == grid[i-1][j])
                height[i][j] = height[i-1][j] + 1;
            else
                height[i][j] = 1;
        }
    }

    long long ans = 0;

    for (int i = 0; i < m; i++){
        int j = 0;
        while(j < n){

            int start = j;
            long long v = grid[i][j];
            while(j < n && grid[i][j] == v) {
                j++;
            }
            int end = j - 1;

            vector<int> st;

            for (int k = start; k <= end + 1; k++){
                int cur = (k <= end) ? height[i][k] : 0;
                while(!st.empty() && cur < height[i][st.back()]){
                    int topIndex = st.back();
                    st.pop_back();
                    int width = st.empty() ? (k - start) : (k - st.back() - 1);
                    long long area = (long long) height[i][topIndex] * width;
                    if(area > ans)
                        ans = area;
                }
                if(k <= end)
                    st.push_back(k);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}