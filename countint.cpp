#include<iostream>
#include<set>
using namespace std;
set<int> theset;
int main() {
    string s;
    cin >> s;
    string tmp;
    for(auto i:s) {
        if(isdigit(i)) {
            tmp.push_back(i);
        } else if(!tmp.empty()) {
            theset.insert(stoi(tmp));
            tmp = "";
        }
    }
    if(!tmp.empty()) {
        theset.insert(stoi(tmp));
    }
    //for(auto i:theset) cout << i << " ";
    cout << endl;
    cout << theset.size();
}