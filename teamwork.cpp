#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxk = 1e3+5;
int n, k;
int a[maxn];
int dp[maxn];


int main(){
    ifstream fin("teamwork.in");
    ofstream fout("teamwork.out");
    fin >> n >> k;
    for(int i = 1; i <= n; i++) fin >> a[i];


    for(int i = 1; i <= n; i++){
        int pre_max = 0;
        for(int j = 1; j <= k; j++){
            if(i >= j){
                if(a[i-j+1] > pre_max) pre_max = a[i-j+1];
                dp[i] = max(dp[i], dp[i-j]+pre_max*j);
            }
        }
    }

    fout << dp[n];
    fin.close();
    fout.close();
    return 0;
}