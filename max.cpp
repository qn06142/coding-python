#include<bits/stdc++.h>
using namespace std;
int main() {
    char s[100];
    cin.getline(s, 100);
    char * p;
    p = strtok(s, " ");
    int currmax;
    for (int i; i <= p.size(); i++) {
    	currmax = max(currmax, p[i]);
    }
    cout << currmax;
}
