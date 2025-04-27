#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, S;
    cin >> n >> m >> S;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for (int i1 = 0; i1 < n - 1; i1++){
        for (int i2 = i1 + 1; i2 < n; i2++){

            unordered_map<int, int> mp; 
            for (int j = 0; j < m; j++){
                int b = a[i1][j] + a[i2][j];
                int need = S - b;

                if (mp.find(need) != mp.end()){
                    int j0 = mp[need];
                    if (j0 < j){ 

                        cout << i1 + 1 << " " << j0 + 1 << " " << i2 + 1 << " " << j + 1;
                        return 0;
                    }
                }

                if (mp.find(b) == mp.end()){
                    mp[b] = j;
                }
            }
        }
    }

    cout << -1;
    return 0;
}