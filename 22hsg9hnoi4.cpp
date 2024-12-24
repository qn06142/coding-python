#include<bits/stdc++.h>

using namespace std;

 

int a[1005][1005],f[1005][1005],m,n;

 

 

void nhap(){

    int x,y,k;

    cin>>m>>n>>k;

    for(int i=1;i<=k;i++){

        cin>>x>>y;

        a[x][y]=1;

    }

}

 

void tinh_pre(){

    for(int i=1;i<=m;i++){

        for(int j=1;j<=n;j++){

            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];

        }

    }

}

 

int s(int x,int y, int z, int t){

    return f[z][t]-f[x-1][t]-f[z][y-1]+f[x-1][y-1];

}

 

void giai(){

    int y,res=0;

    tinh_pre();

    for(int x=1;x<=m;x++){

        for(int z=x;z<=m;z++){

            y=1;

            for(int t=1;t<=n;t++){

                while(s(x,y,z,t)>1) y++;

                if(s(x,y,z,t)==1) res=max(res,(z-x+1)*(t-y+1));

            } 

        }

    }

    cout<<res;

}

 

int main()

{

   ios::sync_with_stdio(false);

   cin.tie(NULL);

  // freopen("b.inp","r",stdin);

  // freopen("b.out","w",stdout);

   nhap();

   giai();

 

}