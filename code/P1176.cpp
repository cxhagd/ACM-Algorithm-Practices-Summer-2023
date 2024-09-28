#include<bits/stdc++.h>
using namespace std;
 int a[1001][1001],b[1001][1001];
	int n,m;int x,y;
int main(){
   
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		
		cin>>x>>y;
		if(x>1||y>1){
		b[x][y]=1;
	}
		}
		a[1][1]=1;
		for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++){
		
		 a[i][j]+=a[i-1][j]+a[i][j-1];
		 if(b[i][j]==1)a[i][j]=0;
		 a[i][j]%=100003;
	}}
		
	cout<<a[n][n];
}