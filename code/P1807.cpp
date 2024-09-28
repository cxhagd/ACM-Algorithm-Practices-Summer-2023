#include<bits/stdc++.h>
using namespace std;
int main(){
    int dis[50001],w[50001],n,m,minn,f[50001][3];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        dis[i]=w[i]=100000000;
        f[i][1]=f[i][2]=0;
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        f[i][1]=a,f[i][2]=b,w[i]=-c;
    }
    dis[1]=0;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            dis[f[j][2]]=min(dis[f[j][2]],dis[f[j][1]]+w[j]);
        }
    }
    if(dis[n]!=0)
    printf("%d",-dis[n]);
    else printf("-1");
    return 0;
}