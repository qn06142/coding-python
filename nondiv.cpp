#include <bits/stdc++.h>
using namespace std;

void kthNonDivisible(int N, int K)
{

	int L = 1; 

	int H = INT_MAX; 

	int ans = 0; 

	while (L <= H) 
	{

		int mid = (L + H) / 2; 

		int sol = mid - mid / N; 

		if (sol > K) 
		{

			H = mid - 1; 
		}

		else if (sol < K) 
		{
			L = mid + 1;
		}

		else
		{

			ans = mid; 

			H = mid - 1; 
		}
	}

	cout << ans;
}

int main()
{
	int N = 3;
	int K = 7;

	kthNonDivisible(N, K);
	return 0;
}