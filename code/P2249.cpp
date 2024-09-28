#include<iostream>
#include<map> 
using namespace std;
int n,m;
int a=-1;
int q;
map<int,int>mp;

int main(){
	cin>>n>>m;
	int t=-1;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a!=t){		
		    mp[a]=i;
		    t=a;
    	}
	}
	for(int i=1;i<=m;i++){
		cin>>q;
		if(mp.count(q)){
		cout<<mp[q]<<" ";
		}else{
			cout<<"-1"<<" ";  
	}
}

}