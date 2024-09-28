#include<iostream>
using namespace std;
int n,k;
int fa[50000*3+11];
int ans=0;
int find(int x){
	if(fa[x]==x){
		return  x;
	}else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void unity(int x,int y){
	int r1=find(fa[x]);
	int r2=find(fa[y]);
	fa[r1]=r2;
}


int main(){
	cin>>n>>k;
	for(int i=1;i<=3*n;i++){
		fa[i]=i;
	}

	for(int q=1;q<=k;q++){
		int z,x,y;
		cin>>z>>x>>y;
		if(x>n||y>n){
		ans++;
		continue;
	}
		if(z==1){
			if(find(x+n)==find(y)||find(y)==find(x+2*n)){
				ans++;
				continue;
			}
			else{
				unity(x,y);
				unity(x+n,y+n);
				unity(x+2*n,y+2*n);
			}
		}
		if(z==2){
			if(find(x)==find(y)||find(x)==find(y+n)){
				ans++;
				continue;
			}
			else{
				unity(x+n,y);
				unity(x+2*n,y+n);
				unity(y+2*n,x);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
	
}