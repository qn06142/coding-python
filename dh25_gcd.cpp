#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using u128 = __uint128_t;

u64 mod_mul(u64 a, u64 b, u64 m){
    return (u128)a*b % m;
}

u64 mod_pow(u64 a, u64 e, u64 m){
    u64 r=1;
    while(e){
        if(e&1) r=mod_mul(r,a,m);
        a=mod_mul(a,a,m);
        e>>=1;
    }
    return r;
}

bool is_prime(u64 n){
    if(n<2) return false;
    for(u64 p: {2,3,5,7,11,13,17,19,23,29,31,37})
        if(n%p==0) return n==p;
    u64 d=n-1, s=0;
    while(!(d&1)){ d>>=1; s++; }
    for(u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}){
        u64 x=mod_pow(a%n,d,n);
        if(x==1||x==n-1) continue;
        bool comp=true;
        for(u64 r=1;r<s;r++){
            x=mod_mul(x,x,n);
            if(x==n-1){ comp=false; break; }
        }
        if(comp) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<u64> a(n);
    for(auto &x:a) cin>>x;

    const int LIM = 1000000;
    vector<int> primes;
    vector<bool> is_composite(LIM+1,false);
    for(int i=2;i<=LIM;i++){
        if(!is_composite[i]){
            primes.push_back(i);
            if((long long)i*i <= LIM)
                for(int j=i*i;j<=LIM;j+=i)
                    is_composite[j]=true;
        }
    }

    unordered_map<u64,int> cnt;
    cnt.reserve(n*3);
    for(u64 x: a){
        u64 orig = x;

        for(int p:primes){
            if((u64)p*(u64)p > x) break;
            if(x%p==0){
                cnt[p]++;
                while(x%p==0) x/=p;
            }
        }
        u64 r = (u64)floor(sqrtl((long double)x) + 0.5L);
        if (r*r == x && is_prime(r)) {
            cnt[r]++;
        }
        if(x>1){
            cnt[x]++;
        }

    }
    int best = 0;
    for(auto &kv:cnt)
        best = max(best, kv.second);

    cout << best << "\n";
}