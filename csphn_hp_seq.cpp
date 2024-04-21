#include<bits/stdc++.h>
using namespace std;
int arr[(int) 1e5 + 5];
long long countSub(int n)
{

	long long count[10] = {0};

	for (int i=0; i<n; i++)
	{

		for (int j=arr[i]-1; j>=0; j--)
			count[arr[i]] += count[j];

		count[arr[i]]++;
	}

	long long result = 0;
	for (int i=0; i<10; i++)
		result += count[i];

	return result;
}

int main()
{
    int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	cout << countSub(n);
	return 0;
}