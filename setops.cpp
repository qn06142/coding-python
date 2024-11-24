#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<db, db> pdb;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef pair<ll, int> pli;
typedef pair<ll, pii> plii;

template<class A, class B>
    bool maximize(A& x, B y) {
        if (x < y) return x = y, true; else return false;
    }
template<class A, class B>
    bool minimize(A& x, B y) {
        if (x > y) return x = y, true; else return false;
    }

int q;

multiset<int> s;

void thao_tac_1(int x) {
    s.insert(x);
}

void thao_tac_2(int x) {
    if (s.find(x) == s.end()) return ;
    s.erase(s.find(x)); 
}

void thao_tac_3(int x) {
    if (s.find(x) == s.end()) cout<<"NO "; else cout<<"YES ";
    set<int>::iterator it = s.lower_bound(x); 
    if (it == s.begin()) {
        cout<<-1<<"\n";
        return ;
    }
    it--;
    cout<<*it<<"\n";
}

void thao_tac_4(int x) {
    if (s.find(x) == s.end()) cout<<"NO "; else cout<<"YES ";
    set<int>::iterator it = s.upper_bound(x);
    if (it == s.end()) {
        cout<<-1<<"\n";
        return ;
    }
    cout<<*it<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>q;
    for (int i = 1; i <= q; i++) {
        int t, x;
        cin>>t>>x;

        if (t == 1) thao_tac_1(x); else
        if (t == 2) thao_tac_2(x); else
        if (t == 3) thao_tac_3(x); else thao_tac_4(x);

    }
    return 0;
}