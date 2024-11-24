#include <bits/stdc++.h>
using namespace std;

bool sortbyCond(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first != b.first)
		return (a.second < b.second);
	else return (a.first > b.first);
}

int main()
{

	vector<pair<int, int>> vect;

	int n;
    cin >> n;
	for (int i = 0; i < n; i++){
        int tmp, tmp1;
        cin >> tmp >> tmp1;
		vect.push_back(make_pair(tmp, tmp1));
    }

	sort(vect.begin(), vect.end(), sortbyCond);

	for (int i = 0; i < n; i++) {
		cout << vect[i].first << " " << vect[i].second << endl;
	}
	return 0;
}