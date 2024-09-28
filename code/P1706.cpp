#include<iostream>
#include<algorithm>
using namespace std;
int a[11];
int main(){
	int n;
	cin>>n;
	int N=1;
	for(int i=1;i<=n;i++){
		a[i]=n-i+1;
		N*=i;
	}
	for(int i=1;i<=N;i++){
		next_permutation(&a[1],&a[n+1]);
		for(int j=1;j<=n;j++){
			 cout<<"    "<<a[j];
		}
		cout<<endl;
	}
	
}