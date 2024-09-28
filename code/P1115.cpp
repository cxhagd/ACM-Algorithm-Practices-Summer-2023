#include<iostream>
using namespace std;

int k,renew,ans=-2147483647,num;


int main(){
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>num;
		if(i==1){
			renew=num;
		}else{
			renew=max(num,renew+num);
		}
		ans=max(ans,renew);
	}
	cout<<ans<<endl;
}