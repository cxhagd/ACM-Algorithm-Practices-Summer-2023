#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
int num[401];

int f[45][45][45][45];
int mp[6]={0};





int main(){
	cin>>N>>M;
	for(int i=1;i<=N;i++){
		cin>>num[i];
	
		
	}
	for(int i=1;i<=M;i++){
		int pok;
		cin>>pok;	
		mp[pok]++;
	}
	f[0][0][0][0]=num[1];
	for(int a=0;a<=mp[1];a++){
		for(int b=0;b<=mp[2];b++){
			for(int c=0;c<=mp[3];c++){
				for(int d=0;d<=mp[4];d++){
					int s=1+a*1+b*2+c*3+d*4;
					if(a!=0){
						f[a][b][c][d]=max(f[a][b][c][d],f[a-1][b][c][d]+num[s]);
					}
					if(b!=0){
						f[a][b][c][d]=max(f[a][b][c][d],f[a][b-1][c][d]+num[s]);
					}
					if(c!=0){
						f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c-1][d]+num[s]);
					}
					if(d!=0){
						f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c][d-1]+num[s]);
					}
				}
			}
		}
	}
	cout<<f[mp[1]][mp[2]][mp[3]][mp[4]]<<endl;
	
}