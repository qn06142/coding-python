#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, X;
    cin >> q >> X;
    
    // Lưu số lượng phần tử theo số dư modulo X
    vector<int> freq(X, 0);
    int current_mex = 0;
    
    while(q--){
        int v;
        cin >> v;
        int r = v % X;
        freq[r]++;
        
        // Tăng current_mex khi có đủ phần tử để “đổ đầy”
        while(freq[current_mex % X] > current_mex / X)
            current_mex++;
        
        cout << current_mex << "\n";
    }
    
    return 0;
}
