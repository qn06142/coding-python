#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n,q; string s,trans[5000009];
struct TrieNode
{
    vector<int> child; int cnt,mxf;
    TrieNode():child(26,-1){cnt=mxf=0;}
};
vector<TrieNode> Raven={TrieNode()};
void Insert(string& str)
{
    vector<int> pos={0};
    for(int i=0;i<str.size();++i)
    {
        if(Raven[pos.back()].child[str[i]-97]==-1)
        {
            Raven[pos.back()].child[str[i]-97]=Raven.size();
            Raven.push_back(TrieNode());
        }
        pos.push_back(Raven[pos.back()].child[str[i]-97]);
        if(i==str.size()-1)
        {
            ++Raven[pos.back()].cnt;
            trans[pos.back()]=str;
        }
    }
    for(int i=pos.size()-1;i>=0;--i)
    {
        Raven[pos[i]].mxf=pos[i];
        for(int j=0;j<26;++j)
        {
            if(Raven[pos[i]].child[j]!=-1)
            {
                if(Raven[Raven[pos[i]].mxf].cnt<Raven[Raven[Raven[pos[i]].child[j]].mxf].cnt)
                    Raven[pos[i]].mxf=Raven[Raven[pos[i]].child[j]].mxf;
            }
        }
    }
}
int main()
{
    if(fopen("D:/CPP/THEMIS/test.inp","r"))
    {
        freopen("D:/CPP/THEMIS/test.inp","r",stdin);
        freopen("D:/CPP/THEMIS/test.out","w",stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        Insert(s);
    }
    cin>>q;
    while(q--)
    {
        cin>>s;
        int pos=0;
        for(int i=0;i<s.size();++i)
        {
            pos=Raven[pos].child[s[i]-97];
            if(pos==-1) break;
        }
        if(pos==-1) cout<<"-1\n";
        else cout<<trans[Raven[pos].mxf]<<" "<<Raven[Raven[pos].mxf].cnt<<'\n';
    }
}