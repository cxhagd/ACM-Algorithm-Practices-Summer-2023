#include<iostream>
using namespace std;
int T,M;
int dp[111][1011];
int v[100+11],w[100+11];
int main(){
	cin>>T>>M;
	for(int i=1;i<=M;i++){
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=M;i++){
		for(int j=T;j>=0;j--){
			if(j>=w[i]){//容量还放得下，看要不要放 
				dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
			}else{
				dp[i][j]=dp[i-1][j];//容量放不下了，维持相等 
			}
		
			
		}
	}
	
	cout<<dp[M][T]<<endl; 
	
}