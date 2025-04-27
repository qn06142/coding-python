#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int nseq;
    cin >> nseq;

    long long tots = 0;   
    long long fevn = 0;   
    long long fodd = 0;   
    vector<long long> bons; 

    for (int i = 0; i < nseq; i++){
        int lnum;
        cin >> lnum;
        vector<long long> data(lnum);
        for (int j = 0; j < lnum; j++){
            cin >> data[j];
            tots += data[j];
        }
        if (lnum % 2 == 0) {  
            int k = lnum / 2;
            long long lsum = 0, rsum = 0;
            for (int j = 0; j < k; j++){
                lsum += data[j];
            }
            for (int j = k; j < lnum; j++){
                rsum += data[j];
            }
            fevn += (lsum - rsum);
        }
        else {  
            int k = lnum / 2;
            long long lsum = 0, rsum = 0;
            for (int j = 0; j < k; j++){
                lsum += data[j];
            }
            for (int j = k; j < lnum; j++){
                rsum += data[j];
            }
            fodd += (lsum - rsum);
            bons.push_back(2 * data[k]); 
        }
    }

    sort(bons.begin(), bons.end(), greater<long long>());
    long long bali = 0;  
    for (size_t i = 0; i < bons.size(); i += 2){
        bali += bons[i];
    }

    long long diff = fevn + fodd + bali;  
    long long ali = (tots + diff) / 2;      
    long long baba = (tots - diff) / 2;     

    cout << ali << " " << baba << "\n";

    return 0;
}