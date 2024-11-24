#include<bits/stdc++.h> 
#include<string>
#define endl "\n"
using namespace std; 
stack<string> subs;
void Substrings(string s, int n) 
{
    /*
     * Fix start index in outer loop.
     * Reveal new character in inner loop till end of string.
     * Print till-now-formed string.
     */
    for (int i = 0; i < n; i++)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = s[j];
            temp[tempindex] = '\0';
            printf("%s\n", temp);
        }
    }
}
 

int main() 
{ 
    string str;
	int k; 
    cin >> str;
    cin >> k;
    Substrings(str, str.length());
    while (!subs.empty()){
    	cout << subs.top() << endl;
    	subs.pop();
    }
} 

