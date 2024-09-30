#include <bits/stdc++.h>

using namespace std;

#define INF (long long)1e+18

int main(void){
	int n;
	long long x,dp0=0,dp1=-INF,tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		tmp=dp0;
		dp0=max(dp1+2*x,dp0);
		dp1=max(tmp+x,dp1);
	}
	cout<<max(dp0,dp1)<<endl;
	return 0;
}
